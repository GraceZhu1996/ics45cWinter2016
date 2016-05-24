/*
 * MapArray.h
 *
 *  Created on: Mar 2, 2016
 *      Author: kezijia
 */

#ifndef MAPARRAY_H_
#define MAPARRAY_H_

template <typename T1, typename T2>
class MapArray
{
	public:
		template <typename F, typename S>
		struct pair
		{
			F first;
			S second;
			pair(const F & a = F(), const S & b = S())
			: first(a), second(b) {}
			pair<F,S> make_pair(const F & a, const S & b) { return pair<F,S>(a,b); }
		};

		struct iterator
		{
			// Iterator traits
			typedef std::random_access_iterator_tag iterator_category;
			typedef iterator self_type;
			typedef pair<T1, T2> value_type;
			typedef pair<T1, T2>& reference;
			typedef pair<T1, T2>* pointer;

			private:
				pair<T1,T2> * p;
			public:
				iterator(pair<T1, T2> * ptr) : p(ptr) {}
				self_type operator++() { ++p; return *this; }
				self_type operator++(int postfix) { self_type cpy = *this; p++; return cpy; }
				self_type operator--() { --p; return *this; }
				self_type operator--(int postfix) { self_type cpy = *this; p--; return cpy; }
				reference operator * () { return *p; }
				pointer operator -> () { return p; }
				bool operator == (const self_type& rhs) const { return p->first == rhs.p->first; }
				bool operator != (const self_type& rhs) const { return !(p->first == rhs.p->first); }
				bool operator > (const self_type& rhs) const { return p->first > rhs.p->first; }
				bool operator < (const self_type& rhs) const { return p->first < rhs.p->first; }
				bool operator <= (const self_type& rhs) const { return !(p->first > rhs.p->first); }
				bool operator >= (const self_type& rhs) const { return !(p->first < rhs.p->first); }
				self_type operator += (int i)
				{
					if( i >= 0 )
						for(; i >= 0; --i)
							++p;
					else
						for(; i <= 0; ++i)
							--p;
					return *this;
				}
				self_type operator + (int i)
				{
					iterator temp = *this;
					return temp += i;
				}
				self_type operator -= (int i)
				{
					return *this += -i;
				}
				self_type operator - (int i)
				{
					iterator temp = *this;
					return temp -= i;
				}
		};

		class const_iterator
		{
			public:
				// Iterator traits
				typedef std::random_access_iterator_tag iterator_category;
				typedef const_iterator self_type;
				typedef pair<T1, T2> value_type;
				typedef pair<T1, T2>& reference;
				typedef pair<T1, T2>* pointer;

			private:
				pointer p;
			public:
				const_iterator(pointer ptr) : p(ptr) {}
				self_type operator++() { ++p; return *this; }
				self_type operator++(int postfix) { self_type cpy = *this; p++; return cpy; }
				self_type operator--() { --p; return *this; }
				self_type operator--(int postfix) { self_type cpy = *this; p--; return cpy; }
				const reference operator * () { return *p; }
				const pointer operator -> () { return p; }
				bool operator == (const self_type& rhs) const { return p->first == rhs.p->first; }
				bool operator != (const self_type& rhs) const { return !(p->first == rhs.p->first); }
				bool operator > (const self_type& rhs) const { return p->first > rhs.p->first; }
				bool operator < (const self_type& rhs) const { return p->first < rhs.p->first; }
				bool operator <= (const self_type& rhs) const { return !(p->first > rhs.p->first); }
				bool operator >= (const self_type& rhs) const { return !(p->first < rhs.p->first); }
				self_type operator += (int i)
				{
					if( i >= 0 )
						for(; i >= 0; --i)
							++p;
					else
						for(; i <= 0; ++i)
							--p;
					return *this;
				}
				self_type operator + (int i)
				{
					iterator temp = *this;
					return temp += i;
				}
				self_type operator -= (int i)
				{
					return *this += -i;
				}
				self_type operator - (int i)
				{
					iterator temp = *this;
					return temp -= i;
				}
		};

		MapArray() : sz(0), buf( new pair<T1, T2>[sz] ) {}
		MapArray( std::initializer_list<pair<T1, T2>> ap ) : true_sz( ap.size() ), sz( ap.size() ), buf( new pair<T1, T2>[ap.size()] ) { std::uninitialized_copy(ap.begin(), ap.end(), buf); }
		int size() const { return true_sz; }
		iterator begin() { return iterator(buf); }
		iterator end() { return iterator(buf + true_sz); }
		T2& operator [] (T1 index)
		{
			for(int i = 0; i < true_sz; ++i)
				if( index == buf[i].first )
					return buf[i].second;
			ensure_length( true_sz + 1 );
			++true_sz;

			// copy a same buf to temp
			pair<T1, T2> * temp = new pair<T1, T2>[true_sz];
			for(int j = 0; j < true_sz - 1; ++j)
			{
				temp[j].first = buf[j].first;
				temp[j].second = buf[j].second;
			}

			// insert to right spot
			// 1. In the middle:
			pair<T1, T2> pr = pair<T1, T2>(index, T2());
			int insertPosition;
			for(int k = 0; k < true_sz - 1; ++k)
				if( index < temp[k].first )
				{
					temp[k] = pr;
					insertPosition = k;
					for(int l = k + 1; l < true_sz; ++l)
						temp[l] = buf[l - 1];
					delete[] buf;
					buf = temp;
					return buf[insertPosition].second;
				}

			// 2. At the end;
			delete[] buf;
			temp[true_sz - 1] = pr;
			buf = temp;
			return buf[true_sz - 1].second;
		}
		const T2& operator [] (T1 index) const
		{
			for(int i = 0; i < true_sz; ++i)
				if (buf[i].first == index)
					return buf[i].second;
		}
		const_iterator begin() const { return const_iterator(buf); }
		const_iterator end() const { return const_iterator(buf + true_sz); }
		~MapArray() { delete[] buf; }

	private:
		pair<T1,T2> * buf;
		int sz = 0;
		int true_sz = 0;
		void ensure_length(int new_length)
		{
			if ( sz >= new_length )
				return;
			pair<T1, T2> * old_buf = buf;
			sz = std::max(new_length,2*sz);
			buf = new pair<T1, T2>[sz];
			for (int i = 0; i < true_sz; ++i)
				buf[i] = old_buf[i];

			delete [] old_buf;
		}
};



#endif /* MAPARRAY_H_ */
