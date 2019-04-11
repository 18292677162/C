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
String& operator=(const String& s)£»
~String()£»
Iterator Begin()£»
Iterator End()£»
Iterator RBegin()£»
Iterator REnd()£»
void PushBack(char c)£»
void Append(const char* str)£»

//////////////////////////////////////////////
char& operator[](size_t index)£»

const char& operator[](size_t index)const£»

///////////////////////////////////////////
void ReSize(size_t newSize, char c);
void Reserve(size_t newCapacity);
int Size()const£»
bool Empty()const£»
void Clear()£»
int Find(char c, size_t pos = 0)£»
int rFind(char c)£»
const char* C_Str()const£»
void Swap(String& s)£»
String StrSub(size_t pos, size_t size)£»

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
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		String(const char* str, size_t size);

		String(const String& s)
			:_str(new char[s._capacity + 1])
			, _size(s._size)
			, _capacity(s._capacity)
		{
			strcpy(_str, s._str);
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
		//modifyÐÞ¸Ä²Ù×÷
		void PushBack(char c)	//Î²²åÒ»¸ö×Ö·û
		{
			if (_size == _capacity){
				Reserve(_capacity * 2);
			}
			_str[_size++] = c;
			_str[_size] = '\0';
		}
			
		void Append(size_t n, char c)	//×·¼Ón¸ö×Ö·ûc
		{
			for (size_t i = 0; i < n; i++){
				PushBack(c);
			}
		}

		void Append(const char* str)	//×·¼Ó×Ö·û´®
		{
			for (size_t i = 0; i < strlen(str); i++){
				PushBack(str[i]);
			}
		}

		String& operator+=(const char c)	//×·¼Ó×Ö·û
		{
			PushBack(c);
			return *this;
		}

		String& operator+=(const char* str)	//×·¼Ó×Ö·û´®
		{
			Append(str);
			return *this;
		}
		bool Empty()const;
		void Clear();
		int Find(char c, size_t pos = 0);
		int rFind(char c);
		//////////////////////////////////////////////
		char& operator[](size_t index);

		const char& operator[](size_t index)const;

		///////////////////////////////////////////
		void ReSize(size_t newSize, char c);
		void Reserve(size_t newCapacity);
		int Size()const;


		
		const char* C_Str()const
		{
			return _str;
		}
		
		void Swap(String& s);
		String StrSub(size_t pos, size_t size);

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

	void StringTest1()
	{
		String s1("hello");
		String s2("goodbye");
		String s1cp(s1);
		cout << s1.C_Str() << endl;
		cout << s2.C_Str() << endl;
		cout << s1cp.C_Str() << endl;
		//µü´úÆ÷´òÓ¡ÔªËØ
		String::Iterator it = s1.Begin();
		while (it != s1.End()){
			cout << *it << " ";
			it++;
		}
	}
};

