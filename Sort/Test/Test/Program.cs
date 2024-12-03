namespace Test
{
    internal class Program
    {
        static void display(int[] array)
        {
            for(int i=0; i<array.Length; i++)
            {
                Console.Write(array[i] + " ");
            }
            Console.WriteLine();
        }
        static void bubbleSort(int[] arr)
        {
            int n = arr.Length;
            for(int i=0; i< n; i++)
            {
                for(int j=0; j<n-1; j++)
                {
                    if (arr[j] > arr[j+1])
                    {
                        int temp = arr[j+1];
                        arr[j+1] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
        }
        static void insertSort(int[] arr)
        {
            int n = arr.Length;
            for(int i=0; i<n; i++)
            {
                int value = arr[i];
                int j = i - 1;
                while (j>=0 && arr[j]>value)
                {
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j + 1] = value;
                
            }
        }

        static void selectSort(int[] arr)
        {
            int n = arr.Length;
            for(int i=0; i < n-1; i++)
            {
                int minIndex = i;
                for(int j=i+1; j<n; j++)
                {
                    if (arr[j] < arr[minIndex])
                    {
                        minIndex = j;
                    }
                }
                int temp = arr[minIndex];
                arr[minIndex] = arr[i];
                arr[i] = temp;
            }
        }
        static void Main(string[] args)
        {
            int[] array = new int[] { 9, 4, 1, 2, 5, 6, 8, 7, 0, 3 };
            display(array);
            selectSort(array);
            display(array);
        }
    }
}
