set NODE;
param b{NODE};
param infinite_arc_cost;
param c{NODE, NODE} default infinite_arc_cost;

var x{NODE, NODE} binary;

minimize path_cost: sum {i in NODE, j in NODE} c[i, j]*x[i, j];
s.t. balance{v in NODE}:
	sum {i in NODE} x[i, v] - sum {j in NODE} x[v, j] = b[v];