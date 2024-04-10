//https://en.cppreference.com/w/cpp/container/array
#include <vector>
#include <string>
#include <iostream>
#include <concepts>
using namespace std;
#pragma once
#ifndef ITERATOR_H
#define ITERATOR_H
#endif // !1




struct FIO
{
	string surname;
	string name;
	string fathername;

	bool operator ==(FIO b)
	{
		if (name == b.name and surname == b.surname and fathername == b.fathername) return true;
		return false;
	}


	
	FIO() {};
	FIO(string surname, string name, string fathername) : surname(surname), name(name), fathername(fathername) {};
};


struct DATE
{
	int day;
	int month;
	int years;

	void init()
	{
		int count_m = 0;
		int count_y = 0;
		day = (day < 0) ? 0 : day;
		while (day > 31)
		{
			day -= 31;
			count_m++;
		}
		month += count_m;

		month = (month < 0) ? 0 : month;
		while (month > 12)
		{
			month -= 12;
			count_y++;
		}
		years += count_y;

		years = (years < 0) ? 0 : years;
		while (years < 2030)
			years--;

	}
};


struct adress
{
	std::string town;
	std::string street;
	int house;

	bool operator==(adress b)
	{
		if (town == b.town and street == b.street and house == b.house) return true;
		return false;
	}
	adress() {};
	adress(std::string town, std::string street, int house) : town(town), street(street), house(house) {}
};



class category
{
	string name_category;
	
	string get_name_cat() { return name_category; }
};
class buyer
{
public:
	FIO fio;
	adress address;

	buyer(FIO fio, adress address) : fio(fio), address(address) {};
	buyer() {};

	adress get_address()
	{
		return address;
	}

	FIO get_fio()
	{
		return fio;
	}


	bool operator ==(buyer b)
	{
		if (fio == b.fio and address == b.address) return true;
		return false;
	}
};


template<int age>
concept F = (age >= 18);

class employer
{
public:
	string fio_employer;
	string post;
	int age;

	string get_name(FIO fio)
	{
		return fio.name;
	}
	string get_fathername(FIO fio)
	{
		return fio.fathername;
	}
	string get_surname(FIO fio)
	{
		return fio.surname;
	}

private:
	string characteristic;

	string get_characteristic()
	{
		return characteristic;
	}

	void change_characteristic()
	{
		cin >> characteristic;
	}

	void change_post()
	{
		cin >> post;
	}
};



class invoice : public buyer, public employer
{
public:
	char number_invoice;
	string name_product;
	DATE date;
	int quantity;
	
	char get_number()
	{
		return number_invoice;
	}
	void change_number()
	{
		cin >> number_invoice;
	}

private:
	FIO fio_buyer;
	FIO fio_employee;

	string get_name(FIO fio)
	{
		return fio.name;
	}


	string get_fathername(FIO fio)
	{
		return fio.fathername;
	}


	string get_surname(FIO fio)
	{
		return fio.surname;
	}

	void change_fio(FIO fio)
	{
		cin >> fio.surname;
		cin >> fio.name;
		cin >> fio.fathername;
	}
	
	void change_date()
	{
		cout << "Input day";
		cin >> date.day;
		cout << "Input month";
		cin >> date.month;
		cout << "Input years";
		cin >> date.years;
	}

	invoice();
};




class order :public invoice{

	char get_numb()
	{
		return get_number();
	}

	string get_name()
	{
		return name_product;
	}

	int get_quantity()
	{
		return quantity;
	}

	void change_quantity()
	{
		cin >> quantity;
	}

};



template <typename T,  size_t N>
struct container
{
	
	
	T list[N];
	std::size_t list_size = 0;



	container(std::initializer_list<T> l)
	{
		for (const T& val : l)
		{
			list[list_size++] = val;
			if (list_size >= N) break;
		}
	}

	container operator=(container b)
	{
		for (int i = 0; i < N; i++)
		{
			this->list[i] = b[i];
		}
	}

	container() {};
	~container() {}


	T at(int i)
	{
		return list[i];
	}

	T operator[](int i)
	{
		return this->list[i];
	}



	bool operator==(container b)
	{
		if (N != b.size()) return false;
		for (int i = 0; i < N; i++)
		{
			if (list[i] != b.list[i])
				return false;
		}
		return true;
	}


	bool operator!=(container b)
	{
		if (this->size() != b.size()) return true;
		for (int i = 0; i < N; i++)
		{
			if (list[i] != b.list[i])
				return true;
		}
		return false;
	}

	T front()
	{
		return list[0];
	}

	T back()
	{
		return list[N - 1];
	}

	bool empty()
	{
		return (this->list == NULL);
	}

	int size()
	{
		return N;
	}

	int max_size()
	{
		return 32;
	}

	void fill(T el)
	{
		for (int i = 0; i < this->size(); i++)
		{
			this->list[i] = el;
		}
	}



	void swap(T* b)
	{
		int memory;
		for (int i = 0; i < N; i++)
		{
			memory = this->list[i];
			this->list[i] = b[i];
			b[i] = memory;
		}
	}

	bool is_in(T* b)
	{
		bool marker = false;

		for (int i = 0; i < N; i++)
		{
			marker = (list[i] == *b) ? true : false;
			if (marker) return true;
		}
	}


	template<bool Const> struct Iterator
	{
		using iterator_category = std::random_access_iterator_tag;
		using difference_type = std::ptrdiff_t;
		using value_type = std::conditional_t<Const, const T, T>;
		using pointer = std::conditional_t<Const, const T*, T*>;
		using reference = std::conditional_t<Const, const T&, T&>;

		Iterator(pointer ptr) : m_ptr(ptr) {}

		reference operator*() const
		{
			return *m_ptr;
		}
		reference operator[](difference_type n) const
		{
			return *(m_ptr + n);
		}
		pointer operator->()
		{
			return m_ptr;
		}

		Iterator& operator++()
		{
			m_ptr++; return *this;
		}
		Iterator operator++(int)
		{
			Iterator tmp = *this; ++(*this); return tmp;
		}
		Iterator operator+(difference_type b) const
		{
			return Iterator(m_ptr + b);
		}
		Iterator operator-(difference_type b) const
		{
			return Iterator(m_ptr - b);
		}
		Iterator& operator+=(difference_type b)
		{
			m_ptr += b;
			return *this;
		}
		Iterator& operator-=(difference_type b)
		{
			m_ptr -= b;
			return *this;
		}

		difference_type operator-(const Iterator& b) const { return m_ptr - b.m_ptr; }

		bool operator==(const Iterator& b) const { return m_ptr == b.m_ptr; }
		bool operator!=(const Iterator& b) const { return m_ptr != b.m_ptr; }

	private:
		pointer m_ptr;
	};

};


template< std::size_t M, class T, std::size_t N >
constexpr T& get(array<T, M>& a) noexcept
{
	return a[M];
}