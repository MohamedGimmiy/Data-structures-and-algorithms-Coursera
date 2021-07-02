#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using std::cin;
using std::cout;
using std::make_pair;
using std::pair;
using std::swap;
using std::vector;

class HeapBuilder
{
private:
  vector<int> data_;
  vector<pair<int, int>> swaps_;

  void WriteResponse() const
  {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i)
    {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData()
  {
    int n;
    cin >> n;
    data_.resize(n);
    for (int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void shiftDown(vector<int> &arr, int i)
  {

    int minIndex = i;


    if (((2 * i) + 1) < arr.size() && arr[((2 * i) + 1)] < arr[minIndex])
    {
      minIndex = ((2 * i) + 1);
    }


    if (((2 * i) + 2) < arr.size() && arr[(2 * i) + 2] < arr[minIndex])
    {
      minIndex = ((2 * i) + 2);
    }

    if (i != minIndex)
    {
      swap(arr[i], arr[minIndex]);
      swaps_.push_back(make_pair(i, minIndex));
      shiftDown(arr, minIndex);
    }
  }

  /**
   * @brief Converting our array into a maxHeap
   * 
   */
  void BuildHeap(vector<int> &A)
  {
    for (int i = (A.size() / 2) - 1; i >= 0; i--)
    {
      shiftDown(A, i);
    }
  }

  void GenerateSwaps()
  {
    swaps_.clear();
    BuildHeap(data_);
  }

public:
  void Solve()
  {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main()
{
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}

