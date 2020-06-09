#pragma once

#include "tools.hpp"

namespace homework {
  // 1.1 - Populations, Samples, and ...
  namespace one {
    namespace section2 {
      void a() {
        vector<int> nums(9); // make a vector with indices [0,9) = [0,8]
        
        tools::put_number_of_nums_in_vector(nums, "transducers.txt");
        
        for (int i = 0; i < nums.size(); ++i) {
          double freq = tools::round_x_decimal_places(nums[i] / 60.0f, 3);
          printf("%d: %d, %0.3f\n", i, nums[i], freq);
        }
      }
      void b() {
        vector<int> nums(9); // make a vector with indices [0,9) = [0,8]
        
        tools::put_number_of_nums_in_vector(nums, "transducers.txt");
        
        double sum = 0;
        for (int i = 0; i <= 5; ++i)
          sum += (nums[i] / 60.0);
        printf("sum: %0.3f\n", tools::round_x_decimal_places(sum, 3));
        
        sum = 0;
        for (int i = 0; i < 5; ++i)
          sum += (nums[i] / 60.0);
        printf("sum: %0.3f\n", tools::round_x_decimal_places(sum, 3));
        
        sum = 0;
        for (int i = 5; i < nums.size(); ++i)
          sum += (nums[i] / 60.0);
        printf("sum: %0.3f\n", tools::round_x_decimal_places(sum, 3));
      }
    
      /*
      Use this in R to make it work:
      vec = c()
      hist(vec, xlab = "number", col = "blue", xlim = c(0,8), ylim = c(0,25))
      */
      vector<double> c()
      {
        vector<double> nums;
        tools::put_nums_in_vector(nums, "transducers.txt");
        return nums;
      }
    }
    namespace section3 {
      /*
      Use this in R to make it work:
      barplot(func())
      */
      vector<double> a()
      {
        vector<double> nums;
        tools::put_nums_in_vector(nums, "papers.txt");
        
        int sum = tools::sum_vector(nums);
        for (int i = 0; i < nums.size(); ++i)
          nums[i] = ((nums[i] / sum) * 100);
    
        return nums;
      }
      void b() {
        vector<int> nums;
        tools::put_nums_in_vector(nums, "papers.txt");
        
        double sum = 0.0;
        int total = 0;
        for (int i = 0; i < nums.size(); ++i) {
          total += nums[i];
          if (i + 1 >= 5)
            sum += nums[i];
        }
        printf("%0.4f\n", tools::round_x_decimal_places(sum / total, 4));
        
        
        sum = 0.0;
        total = 0;
        for (int i = 0; i < nums.size(); ++i) {
          total += nums[i];
          if (i + 1 >= 10)
            sum += nums[i];
        }
        printf("%0.4f\n", tools::round_x_decimal_places(sum / total, 4));
        
        sum = 0.0;
        total = 0;
        for (int i = 0; i < nums.size(); ++i) {
          total += nums[i];
          if (i + 1 > 10)
            sum += nums[i];
        }
        printf("%0.4f\n", tools::round_x_decimal_places(sum / total, 4));
      }
    }
    namespace section4 {
      void a() {
        vector<int> nums;
        tools::put_nums_in_vector(nums, "particles.txt");
        
        double freq = 0.0;
        int total = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
          total += nums[i];
          freq += nums[i];
        }
        printf("%0.2f\n", tools::round_x_decimal_places(freq / total, 2));
        
        
        freq = 0.0;
        total = 0;
        for (int i = 0; i < nums.size(); ++i) {
          total += nums[i];
          if (i >= 5)
            freq += nums[i];
        }
        
        printf("%0.2f\n", tools::round_x_decimal_places(freq / total, 2));
      }
      void b() {
        vector<int> nums;
        tools::put_nums_in_vector(nums, "particles.txt");
        
        double freq = 0.0;
        int total = 0;
        for (int i = 0; i < nums.size(); ++i) {
          total += nums[i];
          if (5 <= i && i <= 10) // if i is in [5, 10]
            freq += nums[i];
        }
        
        printf("%0.2f\n", tools::round_x_decimal_places(freq / total, 2));
        
        freq = 0.0;
        total = 0;
        for (int i = 0; i < nums.size(); ++i) {
          total += nums[i];
          if (5 < i && i < 10) // if i is in (5, 10)
            freq += nums[i];
        }
        
        printf("%0.2f\n", tools::round_x_decimal_places(freq / total, 2));
      }
    
      // barplot(c())
      map<int,int> c()
      {
        map<int,int> m;
        tools::put_nums_in_map(m, "particles.txt");
        return m;
      }
    }
    namespace section5 {
      // barplot(a())
      map<int, double> a()
      {
        vector<double> y_values;
        tools::put_nums_in_vector(y_values, "fire_load.txt");
        
        map<int, double> m;
        int sum = 0;
        for (int i = 0; i < y_values.size() - 1; ++i)
        {
          m[sum] = (y_values[i+1] - y_values[i]);
          sum += 150;
        }
        m[sum] = 0; // there is no difference for the last one.
        
        return m;
      }
      void b() {
        map<int, double> cumulative;
        
        ifstream in("fire_load.txt", ios::in);
        
        int value = 0;
        double number;
        while (in >> number) //Read number using extraction (>>) operator
        {
          cumulative[value] = number;
          value += 150;
        }
        in.close(); //Close the file stream
        
        double ans = cumulative.find(600)->second / 100.0;
        cout << tools::round_x_decimal_places(ans, 3) << endl;
        
        ans = (100.0 - cumulative.find(1200)->second) / 100.0;
        cout << tools::round_x_decimal_places(ans, 3) << endl;
      }
      void c() {
        map<int, double> cumulative;
        
        ifstream in("fire_load.txt", ios::in);
        
        int value = 0;
        double number;
        while (in >> number) //Read number using extraction (>>) operator
        {
          cumulative[value] = number;
          value += 150;
        }
        in.close(); //Close the file stream
        
        
        map<int, double>::iterator it = cumulative.find(600);
        map<int, double>::iterator end = cumulative.find(1200);
        
        double ans = (end->second - it->second) / 100.0;
        cout << tools::round_x_decimal_places(ans, 3) << endl;
      }
    }
  }
  
  // 1.3-1.4-Measures of Location and Variability
  namespace two {
    namespace section1 {
      void a() {
        vector<double> urban;
        tools::put_nums_in_vector(urban, "urban.txt");
        cout << tools::round_x_decimal_places(tools::vector_mean(urban), 2) << endl;
        
        vector<double> farms;
        tools::put_nums_in_vector(farms, "farm.txt");
        cout << tools::round_x_decimal_places(tools::vector_mean(farms), 2) << endl;
      }
      
      void b() {
        vector<double> urban;
        tools::put_nums_in_vector(urban, "urban.txt");
        sort(urban.begin(), urban.end());
        cout << tools::vector_median(urban) << endl;
        
        vector<double> farm;
        tools::put_nums_in_vector(farm, "farm.txt");
        sort(farm.begin(), farm.end());
        cout << tools::vector_median(farm) << endl;
      }
      
      void c() {
        deque<double> urban;
        tools::put_nums_in_deque(urban, "urban.txt");
        sort(urban.begin(), urban.end());
        urban.pop_front();
        urban.pop_back();
        cout << tools::round_x_decimal_places(tools::deque_mean(urban), 2) << endl;
        
        deque<double> farm;
        tools::put_nums_in_deque(farm, "farm.txt");
        sort(farm.begin(), farm.end());
        farm.pop_front();
        farm.pop_back();
        cout << tools::round_x_decimal_places(tools::deque_mean(farm), 2) << endl;
        
        urban.clear();
        tools::put_nums_in_deque(urban, "urban.txt");
        double trimmed_percentage = (1.0 * 100) / urban.size();
        cout << tools::round_x_decimal_places(trimmed_percentage, 2) << endl;
        
        farm.clear();
        tools::put_nums_in_deque(farm, "farm.txt");
        trimmed_percentage = (1.0 * 100) / farm.size();
        cout << tools::round_x_decimal_places(trimmed_percentage, 2) << endl;
      }
    }
    namespace section3 {
      void a() {
        vector<double> blood;
        tools::put_nums_in_vector(blood, "blood.txt");
        cout << tools::round_nearest_x(tools::vector_median(blood), 5) << endl;
        
        replace(blood.begin(), blood.end(), 137.4, 137.9); // replace 137.4 with 137.9
        cout << tools::round_nearest_x(tools::vector_median(blood), 5) << endl;
      }
    }
    namespace section4 {
      void a() {
        vector<double> cracks;
        tools::put_nums_in_vector(cracks, "cracks.txt");
        
        cout << tools::round_x_decimal_places(tools::vector_mean(cracks), 4) << endl;
        cout << tools::round_x_decimal_places(tools::vector_median(cracks), 4) << endl;
      }
      
      void b() {
        vector<double> cracks;
        tools::put_nums_in_vector(cracks, "cracks.txt");
        
        double last_value = cracks[cracks.size() - 1];
        tools::decrement_last_number_until_median_changes(cracks);
        
        double new_last_value = cracks[cracks.size() - 1];
        cout << last_value - new_last_value << endl;
      }
    }
    namespace section5 {
      void a() {
        bitset<10> bset("0011101100");
        cout << bset.count() / (bset.size() + 0.0) << endl;
      }
      
      void b() {
        bitset<10> bset("0011101100");
        bset.flip();
        
        cout << bset.count() / (bset.size() + 0.0) << endl;
      }
      
      void c() {
        bitset<10> bset("0011101100");
        
        cout << 0.6 * 25 - bset.count() << endl;
      }
    }
    namespace section6 {
      void a() {
        vector<double> nums;
        tools::put_nums_in_vector(nums, "chem.txt");
        sort(nums.begin(), nums.end());
        
        double range = tools::round_x_decimal_places(nums[nums.size() - 1] - nums[0], 2);
        printf("%0.2f\n", range);
      }
      
      void b() {
        vector<double> nums;
        tools::put_nums_in_vector(nums, "chem.txt");
        
        // subtract 180 from each observation
        for (int i = 0; i < nums.size(); ++i)
          nums[i] = nums[i] - 180.0;
        
        double mean = tools::vector_mean(nums); // the assumed mean
        
        double sum = 0;
        for (int i = 0; i < nums.size(); ++i)
          sum += ((nums[i] - mean) * (nums[i] - mean));
        
        cout << tools::round_x_decimal_places(sum / (nums.size() - 1.0), 2) << endl;
      }
      
      void c() {
        vector<double> nums;
        tools::put_nums_in_vector(nums, "chem.txt");
        
        double mean = tools::vector_mean(nums); // the assumed mean
        
        double sum = 0.0;
        for (int i = 0; i < nums.size(); ++i)
          sum += ((nums[i] - mean) * (nums[i] - mean));
        
        cout << tools::round_x_decimal_places(sqrt(sum / (nums.size() - 1.0)), 2) << endl;
      }
      
      void d() {
        vector<double> nums;
        tools::put_nums_in_vector(nums, "chem.txt");
        
        double mean = tools::vector_mean(nums); // the assumed mean
        
        double sum = 0;
        for (int i = 0; i < nums.size(); ++i)
          sum += ((nums[i] - mean) * (nums[i] - mean));
        
        cout << tools::round_x_decimal_places(sum / (nums.size() - 1.0), 2) << endl;
      }
    }
    namespace section7 {
      void a() 
      {
        vector<double> nums;
        tools::put_nums_in_vector(nums, "area.txt");
        
        double sum = 0.0, sum_squared = 0.0l;
        for (int i = 0; i < nums.size(); ++i) {
          sum += nums[i];
          sum_squared += (nums[i] * nums[i]);
        }
        
        cout << tools::round_x_decimal_places(sum, 2) << endl;
        cout << tools::round_x_decimal_places(sum_squared, 2) << endl;
      }
      
      void b() 
      {
        vector<double> nums;
        tools::put_nums_in_vector(nums, "area.txt");
        
        cout << tools::round_x_decimal_places(tools::sample_variance(nums), 3) << endl;
        cout << tools::round_x_decimal_places(tools::sample_standard_deviation(nums), 3) << endl;
      }
    }
  }
}