#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ofstream out;

void write(int mas[], int n)
{
	cout << "\n Sorted: \n";
	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl;
}
void write_out(int mas[], int n)
{
	out.open("D:/GitKraken/Lab_works/3 semester/Algorithms and data structures/Sort/mas.txt");

	cout << "Mas: \n";
	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << " ";
		out << mas[i] << " ";
	}
	cout << endl;
	out.close();
}

void Comb_Sort(int mas[], int n)
{
	int gap = n;
	float shrink = 1.3;
	bool sorted = true;
	while (sorted)
	{
		gap = floor(gap / shrink);
		if (gap <= 1)
		{
			gap = 1;
			sorted = false;
		}

		for (int i = 0; (i + gap) < n; i++)
		{
			if (mas[i] > mas[i + gap])
			{
				swap(mas[i], mas[i + gap]);
				sorted = true;
			}
		}

	}
}

void Insertion_sort(int mas[], int n)
{
	int key, i;
	for (int j = 1; j < n; j++)
	{
		key = mas[j];
		i = j - 1;
		while (i >= 0 && mas[i] > key)
		{
				mas[i + 1] = mas[i];
				mas[i] = key;
				i--;
		}
	}
}

void Selection_sort(int mas[], int n)
{
	int jMin;
	for (int i = 0; i < n -1; i++)
	{
		jMin = i;
		for (int j = i + 1; j < n; j++)
		{
			if (mas[j] < mas[jMin])
			{
				jMin = j;
			}
			
		}
		if (jMin != i)
		{
			swap(mas[jMin], mas[i]);
		}
	}
}

void Shell_Sort(int mas[], int n)
{
	int h, j, key;

	for (h = n / 2; h > 0; h /= 2)
	{
		for (int i = h; i < n; i++)
		{
			key = mas[i];
			for (j = i; j >= h; j -= h)
			{
				if (key < mas[j-h])
					mas[j] = mas[j - h];
				else
					break;
			}
			mas[j] = key;
		}
	}
}

void mas_Radix(int mas[], int n)
{
	for (int i = 0; i < n; i++)
		mas[i] = rand() % 100 + 1;
	cout << "\n Mas: \n";
	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl;
}
int razr(int number)
{
	int count = 0;
	while (number > 1)
	{
		number /= 10;
		count++;
	}
	return count;
}
int Digit(int number, int index)
{
	while (index > 0)
	{
		number /= 10;
		index--;
	}
	return number%10;
}
void Radix_Sort(int* mas, int n)
{
	int* C=new int [10];
	int** temp_mas = new int* [10];
	for (int i = 0; i < 10; i++)
		temp_mas[i] = new int[n];

	int max=0, count =0, a, k=0;
	for (int i = 0; i < n; i++)
	{
		if (max < razr(mas[i]))
			max = razr(mas[i]);
	}
	
	while (count < max)
	{
		k = 0;
		for (int i = 0; i < 10; i++)
			C[i] = 0;
		for (int i = 0; i < n; i++)
		{
			a = Digit(mas[i], count);
			temp_mas[a][C[a]] = mas[i];
			C[a]++;
		}
		for(int i=0;i<10;i++)
			for (int j = 0; j < C[i]; j++)
			{
				mas[k] = temp_mas[i][j];
				k++;
			}
		count++;
	}

	delete[] C;
	for (int i = 0; i < 10; i++)
		delete[] temp_mas[i];
	delete[] temp_mas;
}

void heapify(int mas[], int n, int i)
{
	int maxx = i, l=2*i+1, r=l+1;
	if (l<n && mas[l]>mas[maxx])
		maxx = l;
	if (r<n && mas[r] > mas[maxx])
		maxx = r;

	if (maxx != i)
	{
		swap(mas[i], mas[maxx]);
		heapify(mas, n, maxx);
	}
}
void Heap_Sort(int mas[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(mas, n, i);
	}
	for (int i = n - 1; i >= 0; i--)
	{
		swap(mas[0], mas[i]);
		heapify(mas, i, 0);
	}
}

void Merge(int mas[], int low, int high)
{
	int a = 0, b = 0, mid=(low+high)/2, A_size=mid-low+1, B_size=high-mid;

	int* A = new int[A_size];
	for (int i = 0; i < A_size; i++)
		A[i] = mas[low + i];
	
	int* B = new int[B_size];
	for (int i = 0; i < B_size; i++)
		B[i] = mas[mid+1+i];

	int n = low;

	while (a < A_size && b < B_size)
	{
		if (A[a] <= B[b])
		{
			mas[n] = A[a];
			a++;
		}
		else
		{
			mas[n] = B[b];
			b++;
		}
		n++;
	}
	while (a < A_size)
	{
		mas[n] = A[a];
		a++;
		n++;
	}
	while (b < B_size)
	{
		mas[n] = B[b];
		b++;
		n++;
	}

	delete[]A;
	delete[]B;
}
void Merge_Sort(int A[], int low, int high)
{
	if (low < high)
	{
		Merge_Sort(A, low, (low + high) / 2);
		Merge_Sort(A, (low + high) / 2 + 1, high);
		Merge(A, low, high);
	}
}

void Quick_Sort(int low, int high, int* x)
{
	if (low >= high)
	{
		return;
	}
	int m = (low + high) / 2 + 1;
	int k = x[m];
	int l = low - 1;  
	int r = high + 1;
	while (1)
	{
		do
		{
			l++;
		} while (x[l] < k);
		do
		{
			r--;
		} while (x[r] > k);
		if (l >= r)
		{
			break;
		}
		swap(x[l], x[r]);
	}
	r = l;
	l--;
	Quick_Sort(low, l, x);
	Quick_Sort(r, high, x);
}

void PolyPhaseMerge_Sort(int mas[])
{
	ifstream in, inA, inB;
	ofstream out, outA, outB;

	int size=0,a, b, countA, countB, count;
	bool flag = true, Afull, Bfull;

	in.open("D:/GitKraken/Lab_works/3 semester/Algorithms and data structures/Sort/mas.txt");
	out.open("D:/GitKraken/Lab_works/3 semester/Algorithms and data structures/Sort/out.txt");
	while (in >> a)
	{
		out << a << " ";
		size++;
	}
	in.close();
	out.close();

	for (int partSize = 1; partSize < size; partSize *= 2)
	{
		in.open("D:/GitKraken/Lab_works/3 semester/Algorithms and data structures/Sort/out.txt");
		outA.open("D:/GitKraken/Lab_works/3 semester/Algorithms and data structures/Sort/A.txt");
		outB.open("D:/GitKraken/Lab_works/3 semester/Algorithms and data structures/Sort/B.txt");
		count = 0;
		while (in >> a)
		{
			count++;
			if (flag) 
				outA << a << " ";
			else
				outB << a << " ";
			if (count == partSize)
			{
				count = 0;
				flag = !flag;
			}
		}
		in.close();
		outA.close();
		outB.close();

		inA.open("D:/GitKraken/Lab_works/3 semester/Algorithms and data structures/Sort/A.txt");
		inB.open("D:/GitKraken/Lab_works/3 semester/Algorithms and data structures/Sort/B.txt");
		out.open("D:/GitKraken/Lab_works/3 semester/Algorithms and data structures/Sort/out.txt");

		if (inA >> a)
			Afull = false;
		else
			Afull = true;

		if (inB >> b)
			Bfull = false;
		else
			Bfull = true;

		for (int i = 0; i < size; i += 2 * partSize)
		{
			countA = 0; countB = 0;
			while (countA < partSize && !Afull && countB < partSize && !Bfull)
				if (a < b)
				{
					out << a << " ";
					if (inA >> a)
						Afull = false;
					else
						Afull = true;
					countA++;
				}
				else
				{
					out << b << " ";
					if (inB >> b)
						Bfull = false;
					else
						Bfull = true;
					countB++;
				}

			while (countA < partSize && !Afull)
			{
				out << a << " ";
				if (inA >> a)
					Afull = false;
				else
					Afull = true;
				countA++;
			}
			while (countB < partSize && !Bfull)
			{
				out << b << " ";
				if (inB >> b)
					Bfull = false;
				else
					Bfull = true;
				countB++;
			}
		}

		inA.close();
		inB.close();
		out.close();
	}
	in.open("D:/GitKraken/Lab_works/3 semester/Algorithms and data structures/Sort/out.txt");
	int i = 0;
	while (!in.eof())
	{
		in >> mas[i];
		i++;
	}
	in.close();
}

int main()
{
	cout << "Enter the size of the array \n";
	int n, x; cin >> n;
	int* mas = new int[n];
Start:
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		mas[i] = rand() % 100-50;
	}

	cout << "\n Sort: \n 1. Comb Sort \n 2. Insertion Sort  \n 3. Selection Sort \n 4. Shell Sort \n 5. Radix Sort\n 6. Heap Sort \n 7. Merge Sort \n 8. Quick_Sort \n 9. PolyPhaseMerge_Sort \n Choose a sort number - ";
What:
	cin >> x;
	switch (x)
	{
	case(1):write_out(mas, n); Comb_Sort(mas, n); break;
	case(2):write_out(mas, n); Insertion_sort(mas, n); break;
	case(3):write_out(mas, n); Selection_sort(mas, n); break;
	case(4):write_out(mas, n); Shell_Sort(mas, n); break;
	case(5):mas_Radix(mas, n); Radix_Sort(mas, n); break;
	case(6):write_out(mas, n); Heap_Sort(mas, n); break;
	case(7):write_out(mas, n); Merge_Sort(mas, 0, n - 1); break;
	case(8):write_out(mas, n); Quick_Sort(0, n - 1, mas); break;
	case(9):write_out(mas, n); PolyPhaseMerge_Sort(mas); break;
	case(404): return -1; break;
	default: cout << "Choose another... "; goto What; break;
	}

	write(mas, n);

	goto Start;

	delete []mas;
	return 0;
}