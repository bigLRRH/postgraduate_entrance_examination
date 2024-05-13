// 04
bool binary_search_recur(int arr[100], int low, int high, int key, int &index)
{
    if (low > high)
        return false;
    int mid = (low + high) / 2;
    if (key < arr[mid])
        high = mid - 1;
    else if (key > arr[mid])
        low = mid + 1;
    else
    {
        index = mid;
        return true;
    }
    return binary_search_recur(arr, low, high, key, index);
}

// 05
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
bool find(int arr[100], int value, int &index)
{
    for (int i = 0; i < 100; ++i)
    {
        if (arr[i] == value)
        {
            index = i;
            if (i > 0)
            {
                swap(arr[i], arr[i - 1]);
            }
            return true;
        }
    }
}
typedef struct LinkedNode
{
    int value;
    LinkedNode *next;
} LinkedNode;
bool find(LinkedNode *head, int value, LinkedNode *&ptr)
{
    LinkedNode *currNode = head;
    if (currNode->value == value)
    {
        ptr = currNode;
        return true;
    }
    if (currNode->next && currNode->next->value == value)
    {
        LinkedNode *temp = currNode->next;
        currNode->next = temp->next;
        temp->next = currNode;
        head = temp;
        ptr = temp;
    }
    while (currNode->next->next)
    {
        if (currNode->next->next->value == value)
        {
            LinkedNode *temp = currNode->next->next;
            currNode->next->next = temp->next;
            temp->next = currNode->next;
            currNode->next = temp;
            ptr = temp;
            return true;
        }
    }
    return false;
}

// 6
bool find(int **arr, int n, int value, int &_i, int &_j)
{
    int low = 0, high = n - 1;
    while (low < high)
    {
        int mid = (low + high) / 2;
        int i = mid / n;
        int j = mid - n * i;
        if (value < arr[i][j])
        {
            high = mid - 1;
        }
        else if (value > arr[i][j])
        {
            low = mid + 1;
        }
        else
        {
            _i = i;
            _j = j;
            return true;
        }
    }
    return false;
}

