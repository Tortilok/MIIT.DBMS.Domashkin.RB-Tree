#include "ols.h"

int main() {
	ols test;

	test.add(22);
	test.output();
	test.add(49);
	test.add(69);
	test.add(59);
	test.output();
	test.remove(49);
	cout << test.search(59);
	test.update(2, 30);
	test.output();

	return 0;
}