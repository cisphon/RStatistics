#pragma once

#include <iostream>
#include <deque>
#include <map>
#include <algorithm>
#include <fstream>
#include <string>
#include <ctype.h>
#include <vector>
#include <math.h>
#include <iomanip>
#include <bitset>
#include <chrono>
#include <functional>

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>

using boost::multiprecision::cpp_int;
using cpp_float = boost::multiprecision::cpp_dec_float_100;
using namespace std;

namespace ts {
  template<typename T>
  void put_nums_in_vector(vector<T> &nums, string filename) {
    ifstream in("texts/" + filename, ios::in);

    T number;
    while (in >> number) //Read number using extraction (>>) operator
      nums.push_back(number);

    in.close(); //Close the file stream
  }

  template<typename T>
  void put_nums_in_map(map<int, T> &m, string filename) {
    ifstream in("texts/" + filename, ios::in);

    int i = 0;
    T number;
    while (in >> number) //Read number using extraction (>>) operator
      m[i++] = number;

    in.close(); //Close the file stream
  }

  template<typename T>
  void put_nums_in_deque(deque<T> &nums, string filename) {
    ifstream in("texts/" + filename, ios::in);

    T number;
    while (in >> number) //Read number using extraction (>>) operator
      nums.push_back(number);

    in.close(); //Close the file stream
  }

  void put_number_of_nums_in_vector(vector<int> &nums, const string file) {
    ifstream myfile("texts/" + file);

    string line;
    while (getline(myfile, line)) {
      for (int i = 0; i < line.size(); ++i) {
        char c = line[i];

        if (isdigit(c)) {
          int i = c - 48; // -48 because ascii shit
          ++nums[i]; // increment the nonconforming freq
        }
      }
    }

    myfile.close();
  }

  template<typename T>
  double round_x_decimal_places(T val, int x) {
    stringstream tmp;
    tmp << setprecision(x) << fixed << val;
    return stod(tmp.str());
  }

  template<typename T>
  int round_nearest_x(T val, int x) {
    int num = round(val);
    int result = result = num + x / 2;
    result -= result % x;
    return result;
  }

  template<typename T>
  void print_vector(const vector<T> &vec) {
    for (int i = 0; i < vec.size(); ++i)
      cout << vec[i] << " ";
    cout << endl;
  }

  template<typename T>
  void print_2D_vector(const vector<vector<T>> &matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix[i].size(); ++j) {
        cout << matrix[i][j] << ' ';
      }
      cout << '\n';
    }
  }

  template<typename T>
  void print_deque(const deque<T> &deq) {
    for (int i = 0; i < deq.size(); ++i)
      cout << deq[i] << " ";
    cout << endl;
  }

  template<typename T>
  double vector_mean(const vector<T> &vec) {
    double sum = 0.0;
    for (int i = 0; i < vec.size(); ++i)
      sum += vec[i];
    return sum / vec.size();
  }

  template<typename T>
  double deque_mean(const deque<T> &deq) {
    double sum = 0.0;
    for (int i = 0; i < deq.size(); ++i)
      sum += deq[i];
    return sum / deq.size();
  }

  template<typename T>
  double deque_trimmed_mean(deque<T> &deq, double percent) {
    sort(deq.begin(), deq.end());

    double val = (deq.size() * percent) / 100.0;
    int num = floor(val);
    for (int i = 0; i < num; ++i) {
      deq.pop_back();
      deq.pop_front();
    }
    return deque_mean(deq);
  }

  template<typename T>
  double vector_median(vector<T> vec) {
    sort(vec.begin(), vec.end());
    if (vec.size() % 2 == 0) // if the vector has an even number of nums
      return (vec[vec.size() / 2 - 1] + vec[vec.size() / 2]) / 2.0;
    return vec[vec.size() / 2];
  }

  template<typename T>
  T deque_median(deque<T> deq) {
    sort(deq.begin(), deq.end());
    if (deq.size() % 2 == 0) // if the vector has an even number of nums
      return (deq[deq.size() / 2 - 1] + deq[deq.size() / 2]) / 2.0;
    return deq[deq.size() / 2];
  }

  template<typename T>
  double sum_vector(const vector<T> &nums) {
    double sum = 0;
    for (int i = 0; i < nums.size(); ++i)
      sum += nums[i];
    return sum;
  }

  template<typename T>
  double sum_deque(const deque<T> &nums) {
    double sum = 0;
    for (int i = 0; i < nums.size(); ++i)
      sum += nums[i];
    return sum;
  }

  double increment_first_number_until_median_changes(deque<double> deq) {
    double median = deque_median(deq);
    while (deque_median(deq) == median)
      deq[0] += 0.001; // add 0.001 to the largest value
    return deq[0];
  }

  template<typename T>
  double decrement_last_number_before_median_changes(vector<T> vec) {
    sort(vec.begin(), vec.end()); // sort just in case
    double median = ts::vector_median(vec), num_before = vec[vec.size() - 1];
    while (ts::vector_median(vec) == median)
      vec[vec.size() - 1] -= 0.001;
    double num_after = vec[vec.size() - 1] += 0.001;
    return num_before - num_after;
  }

  template<typename T>
  double increment_first_number_until_median_changes(vector<T> vec) {
    double median = vector_median(vec), num_before = vec[0];
    while (vector_median(vec) == median)
      vec[0] += 0.001; // add 0.001 to the largest value
    double num_after = vec[vec.size() - 1] -= 0.001;
    return num_after - num_before;
  }

  template<typename T>
  T sample_range(vector<T> nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() - 1] - nums[0];
  }

  template<typename T>
  double sample_variance(const vector<T> nums) {
    double mean = vector_mean(nums), sum = 0.0;
    for (int i = 0; i < nums.size(); ++i)
      sum += ((nums[i] - mean) * (nums[i] - mean));
    return sum /= (nums.size() - 1);
  }

  template<typename T>
  double sample_standard_deviation(const vector<T> nums) {
    return sqrt(sample_variance(nums));
  }

  template<typename T>
  vector<double> deviations_from_mean(const vector<T> nums) {
    double mean = vector_mean(nums);

    vector<double> dev(nums.size());
    for (int i = 0; i < nums.size(); ++i)
      dev[i] = nums[i] - mean;

    return dev;
  }

  // factorial
  cpp_int fact(int number) {
    cpp_int num = 1;
    for (int i = 1; i <= number; ++i)
      num *= i;
    return num;
  }

  // permutation
  cpp_int perm(int n, int k) {
    return fact(n) / fact(n - k);
  }

  // choose
  cpp_int ch(int n, int k) {
    return perm(n, k) / fact(k);
  }

  // This is the E(X) formula.
  template<typename T>
  double E(vector<T> x, vector<double> px) {
    double sum = 0;
    for (int i = 0; i < x.size(); ++i)
      sum += (x[i] * px[i]);
    return sum;
  }

  // This is the E(F) formula.
  template<typename T>
  double E(vector<T> x, vector<double> px, double F(double)) {
    transform(x.begin(), x.end(), x.begin(), F); // transform X -> F(X)
    return E(x, px);
  }

  // This is the V(X) "variance" formula.
  template<typename T>
  double V(vector<T> x, vector<double> px) {
    double ex = E(x, px);
    return E(x, px, [](double X) -> double { return X * X; }) - ex * ex;
  }

  // This is the V(X) "variance" formula.
  template<typename T>
  double V(vector<T> x, vector<double> px, double F(double)) {
    transform(x.begin(), x.end(), x.begin(), F); // transform X -> F(X)
    return V(x, px);
  }

  // binomial probabilities
  cpp_float bin(int a, int n, double p) {
    return cpp_float(ch(n,a)) * cpp_float(pow(p, a)) * cpp_float(pow(1-p, n-a));
  }

  // binomal probability with sumation.
  cpp_float P(int start, int end, int n, double p) {
    cpp_float ans;
    for (int i = start; i <= end; ++i)
      ans += bin(i, n, p);
    return ans;
  }
}