#include <iostream>
#include "automata.h"

using namespace std;

/**
 * Constructor for Abstract DFA.
 *
 * @param noStates
 *            Number of states in the DFA.
 */
AbstractDFA::AbstractDFA(int noStates) : n_states(noStates), current_state(noStates > 0 ? 0 : -1), on_trap(false) {}

void AbstractDFA::setFinalStates(const vector<int>& states) {
	final_states = states;//final states contains values [0, n_states)
}

void AbstractDFA::addTransition(int from, int to, char c) {
	transition[{from, c}] = to;
}


/**
 * Reset the automaton to the initial state.
 */
void AbstractDFA::reset() {
	current_state = 0;
	on_trap = false;
}

/**
 * Performs one step of the DFA for a given letter. If there is a transition
 * for the given letter, then the automaton proceeds to the successor state.
 * Otherwise it goes to the sink state. By construction it will stay in the
 * sink for every input letter.
 *
 * @param letter
 *            The current input.
 */
void AbstractDFA::doStep(char letter) {
	if (!on_trap) {
		if (transition.find({ current_state, letter }) != transition.end())
			current_state = transition[{ current_state, letter }];
		else
		{
			on_trap = true;
			current_state = -1;
		}
	}
}

/**
 * Check if the automaton is currently accepting.
 *
 * @return True, if the automaton is currently in the accepting state.
 */
bool AbstractDFA::isAccepting() {
	return !on_trap && std::find(final_states.begin(), final_states.end(), current_state) != final_states.end();
}

/**
 * Run the DFA on the input.
 *
 * @param inputWord
 *            stream that contains the input word
 * @return True, if if the word is accepted by this automaton
 */
bool AbstractDFA::run(const string& inputWord) {
	this->reset();
	for (int i = 0; i < inputWord.length(); i++) {
		doStep(inputWord[i]);
	}
	return isAccepting();
}


/**
 * Construct a new DFA that recognizes exactly the given word. Given a word
 * "foo" the constructed automaton looks like: -> () -f-> () -o-> () -o-> []
 * from every state (including the final one) every other input letter leads
 * to a distinguished sink state in which the automaton then remains
 *
 * @param word
 *            A String that the automaton should recognize
 */
WordDFA::WordDFA(const string& word) : AbstractDFA(word.size()+1) {
	setFinalStates({int(word.size())});

	for (int i = 0; i < word.size(); i++) { 
		addTransition(i, i + 1, word[i]); 
	}
}

/**
 * Construct a new DFA that recognizes comments within source code. There
 * are three kinds of comments: single line comment that starts with // and ends
 * with a newline, multiline comments that starts with (* and ends with *), and
 * multiline comments that starts with { and ends with }
 */
CommentDFA::CommentDFA() : AbstractDFA(8) {
	setFinalStates({ 3 });
	
	/* // comment */
	addTransition(0, 1, '/');
	addTransition(1, 2, '/');

	for (char i = 0; i < 127; i++)
	{
		addTransition(2, 2, i);
	}	

	addTransition(2, 3, '\n');

	/* { comment } */
	addTransition(0, 4, '{');

	for (char i = 0; i < 127; i++)
	{
		addTransition(4, 4, i);
	}

	addTransition(4, 3, '}');

	/* (* comment *) */
	addTransition(0, 5, '(');
	addTransition(5, 6, '*');

	for (char i = 0; i < 127; i++)
	{
		addTransition(6, 6, i);
	}

	addTransition(6, 7, '*');
	
	for (char i = 0; i < 127; i++)
	{
		addTransition(7, 6, i);
	}
	
	addTransition(7, 3, ')');
}

/**
 * Performs one step of the DFA for a given letter. This method works
 * differently than in the superclass AbstractDFA.
 *
 * @param letter
 *            The current input.
 */
void CommentDFA::doStep(char letter) {
	AbstractDFA::doStep(letter);
}


