#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <utility>

/*******************************************************************************/
/* printer																	   */
/*******************************************************************************/
template<typename T>
void	print_int_array(T& int_array) {
	std::cout << "The int array: ";
	for (int i = 0; i < int_array.size(); i++) {
		std::cout << int_array[i];
		if (i != (int_array.size() - 1) )
			std::cout << ", ";
	}
	std::cout << "\n";
}

/*******************************************************************************/
/* get/check arguments														   */
/*******************************************************************************/


/*******************************************************************************/
/* merge insertion sort														   */
/*******************************************************************************/
template<typename T>
void	swap_n_element(T& int_array, int n, int index) {
	if (index + (2 * n) > int_array.size())
		return;
	for (int i = 0; i < n; i++) {
		std::swap(int_array[index + i], int_array[index + i + n]);
	}
}

void	last_insert(std::deque<int>& main_chain) {
	std::deque<int> main_chain_holder;
	std::deque<int> sub_chain;
	int i;

	for (i = 1; i < main_chain.size() - 1; i += 2) {
		sub_chain.push_back(main_chain[i]);
		main_chain_holder.push_back(main_chain[i-1]);
	}
	while (i < main_chain.size()) {
		main_chain_holder.push_back(main_chain[i]);
		i++;
	}
	main_chain.clear();
	std::move(begin(main_chain_holder), end(main_chain_holder), back_inserter(main_chain));

	for (int i = 0; i < sub_chain.size(); i++) {
		for (int j = main_chain.size() - 1; j >=0; j--) {
			if (sub_chain[i] > main_chain[j]) {
				main_chain.insert(main_chain.begin() + j + 1, sub_chain[i]);
				break ;
			} else if (j == 0) {
				main_chain.insert(main_chain.begin(), sub_chain[i]);
			}
		}
	}
}

template<typename T>
void	insert(T& int_array, int pair_by) {
	int rest = int_array.size() % pair_by;
	int	pairs = int_array.size() / pair_by;
	std::deque<int> holder_array;
	if (pairs == 1 && rest != pair_by)
		return;
	if (pairs % 2 != 0 && pairs != 1) {
		pairs -= 1;
		rest += pair_by;
	}
	// take out the rest and do the insertion without them
	while (rest != 0) {
		int value = int_array[(pair_by * pairs) + rest - 1];
		holder_array.push_front(value);
		int_array.erase(int_array.begin() + (pair_by * pairs) + rest - 1);
		rest--;
	}

	// take out all the first element(with pair_by number) and create a vector/deque of.
	std::deque<int> main_chain;
	for (int i = 0; i < pairs; i += 2) {
		for (int j = 0; j < pair_by; j++) {
			main_chain.push_back(int_array[j + i * pair_by]);
		}
	}
	for (int i = 0; i < pairs / 2; i += pair_by) {
		// find the position to insert from the end of the main_chain
		for (int j = main_chain.size() - pair_by; j >= 0; j -= pair_by) {
			if (int_array[i + pair_by] > main_chain[j]) {
				for (int k = 0; k < pair_by; k++) {
					main_chain.insert(main_chain.begin() + j + pair_by + k, int_array[i + k + pair_by]);
				}
			} else if (j == 0) {
				for (int k = 0; k < pair_by; k++) {
					main_chain.insert(main_chain.begin() + j + k, int_array[i + k + pair_by]);
				}
			}
		}
	}
	int_array.clear();
	std::move(begin(main_chain), end(main_chain), back_inserter(int_array));


	// check if we need to insert the rest
	std::cout << "in !!!!!!!!!!!!!!!!!!!!!";
	print_int_array(main_chain);
	if (rest != pair_by && pair_by != 2){

		// no insert of the rest, just add back to int_array
		std::move(begin(holder_array), end(holder_array), back_inserter(int_array));
		return;
	} else {
		for (int i = 0; i < holder_array.size(); i += pair_by) {
		// find the position to insert from the end of the main_chain
			for (int j = main_chain.size() - pair_by; j >= 0; j -= pair_by) {
				if (holder_array[i] > main_chain[j]) {
					for (int k = 0; k < pair_by; k++) {
						main_chain.insert(main_chain.begin() + j + pair_by + k, holder_array[i + k]);
					}
				} else if (j == 0) {
					for (int k = 0; k < pair_by; k++) {
						main_chain.insert(main_chain.begin() + j + k, holder_array[i + k]);
					}
				}
			}
		}
	}
	int_array.clear();
	if (pair_by == 2) {
		// do the last insert
		std::cout << "before last insert: ";
		print_int_array(main_chain);

		last_insert(main_chain);
	}
	std::move(begin(main_chain), end(main_chain), back_inserter(int_array));

}

template<typename T>
void	merge_insertion_sort(T& array, int pair_by) {
/* first pair_by 1, then pair_by 2, then 4 ...etc */
/* if the size of array / pair_by * 2 is 1, stop the recursion */
	if (array.size() / pair_by  == 1) {
		return ;
	}

/* iterate through the array and find the smallist inside each pair */
	for (int i = 0; i < array.size(); i += (pair_by * 2)) {
		if (array[i] > array[i + pair_by]) {
			swap_n_element(array, pair_by, i);
		}
	}

	pair_by *= 2;
	merge_insertion_sort(array, pair_by);
	// after all the recursion and pair sorting, do the insertion
	insert(array, pair_by);
}

/*******************************************************************************/
/* main 																	   */
/*******************************************************************************/
int main(int ac, char **av) {
	// sort vectors
	std::vector<int> vector_a = {1, 3, 5, 22, 44};
	std::vector<int> vector_b = {98,  76, 199, 2, 3 ,44, 5, 5};
	print_int_array(vector_a);
	print_int_array(vector_b);

	merge_insertion_sort(vector_a, 1);
	std::cout << "\n";

	// sort deques
	std::deque<int> deque_a = {7, 1, 3, 5, 22, 13};
	std::deque<int> deque_b = {98,  76, 199, 2, 3 ,44, 188 , 99};

	std::cout << "\n\nbefore sort: \n";
	print_int_array(deque_b);

	std::cout << "\n\nsort deques: \n";
	merge_insertion_sort(deque_b, 1);

	std::cout << "After sort: ";
	print_int_array(deque_b);
}
