#DICHIARAZIONE INSIEMI
set F;							# facilities
set I;							# centroids

#DICHIARAZIONE PARAMETRI
param minFacilities;			# minimum number of facilities
param tresholdQoS;				# threshold distance
param A {I,F};					# distance fality-centroid

var x {F} binary;

minimize cost: sum {f in F} x[f];

subject to soddisfazione {i in I}:
	sum {f in F : A[i,f] <= tresholdQoS} x[f] >= minFacilities;


