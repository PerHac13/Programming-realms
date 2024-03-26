#include <iostream>
#include<cmath>
#include <vector>

// Function to find an SS-good sequence for the given values of N, K, and S
std::vector<int> findSequence(int N, int K, int S) {
  std::vector<int> B;
  
  // If S is 0, then the SS-good sequence is all 0s
  if (S == 0) {
    B.resize(N, 0);
    return B;
  }
  
  // If K is 1, then the SS-good sequence is all 1s or all -1s
  // depending on the value of S
  if (K == 1) {
    if (S == N) {
      B.resize(N, 1);
      return B;
    } else if (S == -N) {
      B.resize(N, -1);
      return B;
    } else {
      // No SS-good sequence exists
      B.resize(1, -2);
      return B;
    }
  }
  
  // For other values of K, we can find an SS-good sequence as follows:
  // Set the first element of the sequence to be S / K^(N-1)
  B.push_back(S / pow(K, N-1));
  
  // Set the remaining elements of the sequence to be the remainder
  // of the division S / K^(N-1) until the remainder is 0
  int remainder = S % static_cast<int>(pow(K, N-1));
  while (remainder != 0) {
    B.push_back(remainder / pow(K, N-2));
    remainder = remainder % static_cast<int>(pow(K, N-2));
    N--;
  }
  
  // Pad the sequence with 0s if necessary to make it of length N
  while (B.size() < N) {
    B.push_back(0);
  }
  
  return B;
}

int main() {
  int T;
  std::cin >> T;
  
  // Process each test case
  for (int i = 0; i < T; i++) {
    int N, K, S;
    std::cin >> N >> K >> S;
    
    // Find an SS-good sequence for the given values of N, K, and S
    std::vector<int> B = findSequence(N, K, S);
    
    // Output the SS-good sequence
    for (int j = 0; j < B.size(); j++) {
      std::cout << B[j] << " ";
    }
    std::cout << std::endl;
  }
  
  return 0;
}