#include <iostream>
#include <stdio.h>

using namespace std;

// logic
// bool flags[max] = {false, false, true,....}
// prime = 2
// cross-off-prime-prod - generate all products of 2 and mark those indices as false
// increment prime until flag is true to find next prime, cross-off-prime-prod
// do it until max is reached.
// now all true flag gives prime #s upto max

void init_flags (bool flags[], int max) {
	flags[0] = false; flags[1] = false;
	for (int i=2; i< max; i++) {
		flags[i] = true;
	}
	return;
}



void print_prime(bool flags[], int max) {
	for (int i=2; i< max; i++) {
		if (flags[i]) cout << i << " ";
	}
	cout << endl;
}

void cross_off_prime_multiples(bool flags[], int max, int prime) {
	int i = prime * prime;
	while (i < max) {
		flags[i] = false;
		i = i + prime;
	}
}

int get_next_prime (int prime, int max, bool flags[]) {
	int i = prime + 1;
	while (i < max) {
		if (flags[i]) {
			return i;
		}
		i++;
	}
	return max;
}

void generate_prime (int max) {
	if (max <= 2) { cout << "max is too small" << endl; return;}
	bool flags[max];
	init_flags(flags, max);
	int prime = 2;
	while (prime < max) {
	  cross_off_prime_multiples(flags, max, prime);
	  prime = get_next_prime(prime, max, flags);
    }
	print_prime(flags, max);
}


int main() {
	int max;
	cout << "enter max: ";
	cin >> max;
	
	generate_prime(max);
	
    return 0;
}
