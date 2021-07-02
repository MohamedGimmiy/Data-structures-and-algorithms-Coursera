#include <iostream>

using namespace std;

// my implementation
class dynamicArray
{

    int *arr;
    int count = 0;
    int size = 0;

public:
    dynamicArray(int size)
    {
        arr = new int[size];
        this->size = size;
        count = size;
    }
    dynamicArray(int size, int filling){
        if(size <= 0){
            cout << "invalid\n";
            return;
        }
        arr = new int[size];
        for (size_t i = 0; i < size; i++)
        {
            arr[i] = filling;
        }
        this->size = size;
        count = size;
    }
    dynamicArray()
    {
        arr = new int[size];
    }

    void insert_back(int element)
    {
        if(count >= size){
            // reallocating our array
            int * newArray = new int[2*size+1];

            for (size_t i = 0; i < size; i++)
            {
                newArray[i] = arr[i];
            }
            free(arr);
            newArray[count] = element;
            arr = newArray;
            count++;
            size = 2*size + 1;
            return;
        }
        arr[count] = element;
        count++;
    }
    int length()
    {
        return count;
    }

    int & operator[](int i){
        if (i >= count || i <= 0) { 
            cout << "Array index out of bound, exiting"; 
            //exit(0); 
    } 
        return arr[i]; 
    }

    void remove(int index){
        if(index >= size){
            cout << "out of index\n";
            return;
        }
        for (size_t i = 0; i < count; i++)
        {
            arr[index] = arr[index+1];
        }
        count--;
    }
};

int main()
{

    dynamicArray a;
    a.insert_back(1);
    //cout << a[0];
    a.insert_back(2);
    a.insert_back(3);
    for (size_t i = 0; i < a.length(); i++)
    {
        /* code */
        cout << a[i] << "\n";
    }
    cout <<a.length() << "\n";

    dynamicArray my(10,2);

    
    my.remove(0);
    my.remove(1);
    my.remove(2);
    my.remove(3);
    my.remove(100);
    for (size_t i = 0; i < my.length(); i++)
    {
        cout << my[i] << "\n";
    }
    cout << my.length();
    my.insert_back(1);
    cout << my.length();
}