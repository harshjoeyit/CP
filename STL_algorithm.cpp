/*
STL Algorithms
*/
#include<bits/stdc++.h>
using namespace std;


template <typename T>
void print(vector<T> v)
{
    for(auto x: v)
        cout << x << " ";
    cout << endl;
}
void print(int a[], int l, int h) {
      for(int i=l; i<=h; i++) {
            cout << a[i] << " ";
      }cout << endl;
}

void tut_heaps() {
      vector<int> v = {1, 2, 3, 4, 5, 6};
      
      make_heap(v.begin(), v.end());
      print(v);

      v.push_back(10);
      // similar to max_heapify
      push_heap(v.begin(), v.end());
      print(v);

      // swaps the v[0] with v[size()-1];
      // the largest element swaps with the largest element
      pop_heap(v.begin(), v.end());
      print(v);
      v.pop_back();
      print(v);
}

void tut_sort() {
      vector<int> v = {9, 5, 11, 4, 3, 6, 1};
      vector<int> v2(v);

      // vector from v.begin() - v.begin()+2 - looks just as it would look when 
      // when the complete array is sorted, the rest elements are unordered
      partial_sort(v.begin(), v.begin()+3, v.end());
      print(v);

      // element at v2.begin()+3 is at its correct position as it would be in sorted array
      nth_element(v2.begin(), v2.begin()+3, v2.end());
      print(v2);

      is_sorted
}

void tut_permutations() {
      vector<int> v = {1, 2, 3, 4};

      rotate(v.begin(), v.end());

      shuffle

      next_permutation

      prev_permutation
}

void tut_numeric() {
      count
      accumulate
      partial_sum
      inner_product
      adjacent_difference

}

void tut_query() {
      all_of
      any_of
      none_of

      // comparing
      equal
      is_permutation
      mismatch

      // searching
      // not sorted
      find
      adjacent_find
      // sorted
      lower_bound
      upper_bound
      binary_search

      max_element
      min_element
      minmax_element
}

void tut_sets() {
      // liner complexity - if input is sorted
      set_difference
      set_union
      set_intersection
}

void tut_movers() {

      copy
      move
      copy_backward
      move_backward
      sor
}


void tut_modifiers() {
      fill
      fill_n
      generate
      iota
      replace 

      unique
      remove
      erase
}

void tut_rest() {
      transform
      for_each

}

int main() {
      // tut_heaps();
      // tut_sort();
      // tut_permutations();
      // tut_numeric();
      // tut_query()
      // tut_sets();
}