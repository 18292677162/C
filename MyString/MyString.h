#include <iostream>
#include <assert.h>

using namespace std;

/*
class String
{
public:
typedef char* Iterator;

public:
String(const char* str);
String(const char* str, size_t size);
String(const String& s);
String& operator=(const String& s)��
~String()��
Iterator Begin()��
Iterator End()��
Iterator RBegin()��
Iterator REnd()��
void PushBack(char c)��
void Append(const char* str)��

//////////////////////////////////////////////
char& operator[](size_t index)��

const char& operator[](size_t index)const��

///////////////////////////////////////////
void ReSize(size_t newSize, char c);
void Reserve(size_t newCapacity);
int Size()const��
bool Empty()const��
void Clear()��
int Find(char c, size_t pos = 0)��
int rFind(char c)��
const char* C_Str()const��
void Swap(String& s)��
String StrSub(size_t pos, size_t size)��

bool operator<(const String& s);
bool operator<=(const String& s);
bool operator>(const String& s);
bool operator>=(const String& s);
bool operator==(const String& s);
bool operator!=(const String& s);
friend ostream& operator<<(ostream& _cout, const String& s);
friend istream& operator>>(istream& _cout, String& s);
private:
char* _str;
size_t _capacity;
size_t _size;
};
*/
namespace MyString
{
	class String
	{
	public:
		typedef char* Iterator;

	public:
		String(const char* str)
		{
			if (nullptr == str){
				assert(false);
				return;
			}
			_size = strlen(str);
			_capacity = strlen(str);
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);

		}

		String(const char* str, size_t size);

		//��ͨ���
		/*String(const String& s)
			:_str(new char[s._capacity + 1])
			, _size(s._size)
			, _capacity(s._capacity)
			{
			strcpy(_str, s._str);
			}*/

		String(const String& s)
		{
			String strTmp(s._str);
			swap(_str, strTmp._str);
		}

		String& operator=(const String& s)
		{
			if (this != &s){
				String strTmp(s);
				swap(_str, strTmp._str);
			}
			return *this;
		}

		~String()
		{
			if (_str){
				delete[] _str;
				_str = nullptr;
			}
		}
		//////////////////////////////////////////////
		//		Iterator
		Iterator Begin()
		{
			return _str;
		}

		Iterator End()
		{
			return _str + _size;
		}

		Iterator RBegin()
		{
			return Begin() - 1;
		}

		Iterator REnd()
		{
			return End() - 1;
		}
		///////////////////////////////////////////////////
		//modify�޸Ĳ���
		void PushBack(char c)	//β��һ���ַ�
		{
			if (_size == _capacity){
				Reserve(_capacity * 2);
			}
			_str[_size++] = c;
			_str[_size] = '\0';
		}

		void Append(size_t n, char c)	//׷��n���ַ�c
		{
			for (size_t i = 0; i < n; i++){
				PushBack(c);
			}
		}

		void Append(const char* str)	//׷���ַ���
		{
			for (size_t i = 0; i < strlen(str); i++){
				PushBack(str[i]);
			}
		}

		String& operator+= (const String& str)		//׷���ַ���
		{
			if (_size == _capacity){
				Reserve(_capacity * 2);
			}
			strcat(_str, str._str);
			_size += strlen(str._str);
		}

		String& operator+=(const char c)	//׷���ַ�
		{
			PushBack(c);
			return *this;
		}

		String& operator+=(const char* str)	//׷���ַ���
		{
			Append(str);
			return *this;
		}

		String& Insert(size_t pos, char c)	//ָ��λ�ò����ַ�
		{
			assert(pos < _size);
			if (_size == _capacity){
				Reserve(_capacity * 2);
			}
			for (int i = _size; i >= (int)pos; i--){
				_str[i] = _str[i - 1];
			}
			_str[pos] = c;
			_size++;
			_str[_size] = '\0';
			return *this;
		}


		int Find(char c, size_t pos = 0)		//��pos�±꿪ʼ�����ַ�c
		{
			assert(pos < _size);
			for (size_t i = pos; i < _size; i++){
				if (c == _str[i]){
					return i;
				}
			}
			return 0;
		}

		int rFind(char c, size_t pos = 0);		//��pos�±���ǰ��c

		String& Erase(size_t pos, size_t len)
		{
			;
		}

		//////////////////////////////////////////////
		//		�±����
		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}

		const char& operator[](size_t index)const
		{
			assert(index < _size);
			return _str[index];
		}

		///////////////////////////////////////////
		//		��������
		void ReSize(size_t newSize, char c)		//��Ч�ַ��ĳ�newSize�����c���
		{
			if (newSize>_size){
				// ������
				if (newSize > _capacity){
					Reserve(newSize);
				}
				memset(_str + _size, c, newSize - _size);
			}
			// newSize<_size
			_size = newSize;
			_str[newSize] = '\0';
		}

		void Reserve(size_t newCapacity)		//Ϊ�ַ���Ԥ���ռ�
		{
			//newcapacity����capacity������
			if (newCapacity > _capacity){
				char* str = new char[newCapacity + 1];
				strcpy(str, _str);
				//�ͷžɿռ䣬ʹ���¿��ٵĿռ�
				delete[] _str;
				_str = str;
				_capacity = newCapacity;
			}
		}

		int Size()const
		{
			return _size;
		}

		bool Empty()const
		{
			return 0 == _size;
		}

		void Clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}

		size_t Capacity()const
		{
			return _capacity;
		}

		const char* C_Str()const
		{
			return _str;
		}

		String StrSub(size_t pos, size_t size);

		bool operator<(const String& s)const
		{
			size_t index1 = 0;
			size_t index2 = 0;
			while (index1 < _size && index2 < s._size){
				if (_str[index1] < s._str[index2]){
					return true;
				}
				index1++;
				index2++;
			}
			return false;
		}

		bool operator==(const String& s)
		{
			if (s._size != _size){
				return false;
			}
			size_t i = 0;
			while (_str[i] == s._str[i] && i < _size){
				i++;
			}
			if (i = _size && s._str[i] == '/0'){
				return true;
			}
			return false;
		}

		bool operator<=(const String& s)
		{
			return *this < s || *this == s;
		}

		bool operator>(const String& s)
		{
			return !(*this <= s);
		}

		bool operator>=(const String& s){
			return !(*this < s);
		}

		bool operator!=(const String& s){
			return !(*this == s);
		}
	private:
		//��Ԫʵ���������<<>>����
		friend ostream& operator<<(ostream& _cout, const String& s);
		friend istream& operator>>(istream& _cout, String& s);

	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};
}

ostream& MyString::operator << (ostream& _cout, const String& s)
{
	cout << s._str;
	return _cout;
}

istream& MyString::operator >> (istream& _cin, String& s)
{
	cin >> s._str;
	return _cin;
}

void StringTest1()
{
	MyString::String s1("hello");
	MyString::String s2("goodbye");
	MyString::String s1cp(s1);
	cout << s1.C_Str() << endl;
	cout << s2.C_Str() << endl;
	cout << s1cp.C_Str() << endl;
	//��������ӡԪ��
	MyString::String::Iterator it = s1.Begin();
	while (it != s1.End()){
		cout << *it << " ";
		it++;
	}
	cout << endl;
	s1.Insert(2, 'A');
	cout << s1.C_Str() << endl;
}


//дʱǳ������count����̬��Ա���� constд��
#if 0
class String
{
public:
	String(const char* str)
		//:_count(1)		��ʼ���б�ֻ�ܳ�ʼ����ǰ�������ͨ��Ա����
		{
			if (nullptr == str){
				assert(false);
				return;
			}
			_size = strlen(str);
			_capacity = strlen(str);
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
			_count = 1;
		}

	String(String& s)
		:_str(s._str)
		//, _count(++s._count)
	{
		_count++;
	}

	~String()
	{
		if (0 == --_count && _str){
			delete[] _str;
			_str = nullptr;
		}
	}
		
private:
	char* _str;
	size_t _capacity;
	size_t _size;
	static int _count;
};

int String::_count = 0;

void TestString()
{
	String s1("hello");
	String s2(s1);
	String s3(s2);
	String s4;
	// ���ɾ�̬��Ա�������г�ʼ��s1s2s3û���⣬����s4��û��ʼ��count�Ѿ�Ϊ3��һ��������count = 1
}

int main()
{
	TestString();
	return 0;
}
#endif

//дʱǳ������count����̬��Ա���� *countд��
#if 0
class String
{
public:
	String(const char* str)
		:_count(new int(1))
	{
		if (nullptr == str){
			assert(false);
			return;
		}
		_size = strlen(str);
		_capacity = strlen(str);
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
		:_str(s._str)
		, _count(s._count)
	{
		(*_count)++;
	}

	String& operator=(const String& s)
	{
		if (this != &s){
			_Release();
			_str = s._str;
			_count = s._count;
			++(*_count);
		}
	}

	~String()
	{
		_Release();
	}
private:
	void _Release()
	{
		if (0 == --(*_count) && _str){
			delete[] _str;
			_str = nullptr;
			delete _count;
		}
	}
private:
	char* _str;
	size_t _capacity;
	size_t _size;
	int* _count;
};

void TestString()
{
	String s1("hello");
	String s2(s1);
	String s3(s2);
	String s4;

}

int main()
{
	TestString();
	return 0;
}
#endif