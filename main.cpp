#include <iostream>

void sort(int *arr, int length);
void merge(int* arr, int first, int second, int end);
void divide_and_merge(int *arr, int left, int right);
int beginningsBinarySearch(int *arr, int array_size, int key);
int endingsBinarySearch(int *arr, int array_size, int key);

int main()
{
    int *beginnings, *endings;
    int periods_number, friends_number;

    std::cin >> periods_number;
    beginnings = new int[periods_number];
    endings = new int[periods_number];

    for (int i = 0; i < periods_number; i++)
    {
        int k;

        std::cin >> k;
        beginnings[i] = k;

        std::cin >> k;
        endings[i] = k;
    }

    sort(beginnings, periods_number);
    sort(endings, periods_number);

    std::cin >> friends_number;

    for (int i = 0; i < friends_number; i++)
    {
        int curHour;
        std::cin >> curHour;

        std::cout << beginningsBinarySearch(beginnings, periods_number, curHour) - endingsBinarySearch(endings, periods_number, curHour) - 1<< "\n";
    }

    delete[] beginnings;
    delete[] endings;
    return 0;
}

void sort(int *arr, int length)
{
    divide_and_merge(arr, 0, length - 1);
}

void merge(int* arr, int first, int second, int end)
{
    int left_size = second - first + 1, right_size = end - second, k;
    int *leftArr = new int[left_size];
    int *rightArr = new int[right_size];

    for (int i = 0; i < left_size; i++)
    {
        leftArr[i] = arr[first + i];
    }

    for (int i = 0; i < right_size; i++)
    {
        rightArr[i] = arr[second + i + 1];
    }

    int left_index = 0, right_index = 0;
    for (k = first; left_index < left_size && right_index < right_size; k++)
    {
        if (leftArr[left_index] < rightArr[right_index])
            arr[k] = leftArr[left_index++];
        else
            arr[k] = rightArr[right_index++];
    }

    while (left_index < left_size)
        arr[k++] = leftArr[left_index++];

    while (right_index < right_size)
        arr[k++] = rightArr[right_index++];

    delete[] leftArr;
    delete[] rightArr;
}

void divide_and_merge(int *arr, int left, int right)
{
    int middle;
    if (left < right)
    {
        middle = (left + right) / 2;
        divide_and_merge(arr, left, middle);
        divide_and_merge(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

int beginningsBinarySearch(int *arr, int array_size, int key)
{
    int left = -1, right = array_size, middle;

    while (right != left + 1)
    {
        middle = (left + right) / 2;

        if (key >= arr[middle])
            left = middle;
        else
            right = middle;
    }

    return right;
}

int endingsBinarySearch(int *arr, int array_size, int key)
{
    int left = -1, right = array_size, middle;

    while(right != left + 1)
    {
        middle = (left + right) / 2;

        if (key <= arr[middle])
            right = middle;
        else
            left = middle;
    }

    return left;
}