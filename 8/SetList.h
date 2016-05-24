/*
 * SetList.h
 *
 *  Created on: Mar 2, 2016
 *      Author: kezijia
 */

#ifndef SETLIST_H_
#define SETLIST_H_

template <typename T>
class SetList
{
	private:
		template <typename LN>
		struct ListNode
		{
			LN info;
			ListNode * next;
			ListNode(LN newInfo, ListNode * newNext)
			: info( newInfo ), next( newNext ) {}
			static LN & findByIndex(ListNode * L, int n)
			{
				return L == nullptr ? (LN &) "\0"
							: n == 0 ? L->info
							: findByIndex(L->next, n - 1);
			}
			static int length(ListNode * L) { return L == nullptr ? 0 : 1 + length( L->next ); }
			static void deleteList(ListNode * L)
			{
				if (L)
				{
				  deleteList( L->next );
				  delete L;
				}
			}
			static void insert(ListNode * &L, T info)
			{
				if( L->info == T() || info < L->info )
					L = new ListNode<T>(info, L);
				else
				{
					ListNode * temp = L;
					for(; temp->next; temp = temp->next )
						if( info < temp->next->info )
							break;
					temp->next = new ListNode<T>(info, temp->next);
				}

			}
		};
		ListNode<T> * head;

	public:
		struct iterator
		{
			// Iterator traits
			typedef std::forward_iterator_tag iterator_category;
			typedef iterator self_type;
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;

			private:
				ListNode<T> * ln;
			public:
				iterator(ListNode<T> * ptr): ln(ptr) {}
				self_type operator++()
				{
					ln = ln->next;
					return *this;
				}
				self_type operator++(int postfix)
				{
					self_type cpy = *this;
					ln = ln->next;
					return cpy;
				}
				reference operator * () { return ln->info; }
				pointer operator -> () { return &(ln->info); }
				bool operator == (const self_type& rhs) const
				{
					if(ln && rhs.ln)
						return ln->info == rhs.ln->info;
					return (!ln && !rhs.ln);
				}
				bool operator != (const self_type& rhs) const { return !(ln->info == rhs.ln->info); }
		};

		class const_iterator
		{
			public:
		        typedef std::forward_iterator_tag iterator_category;
		        typedef const_iterator self_type;
		        typedef T value_type;
		        typedef T& reference;
		        typedef T* pointer;

			private:
		        ListNode<T> * ln;
			public:
		        const_iterator(ListNode<T> * ptr) : ln(ptr) {}
				self_type operator++()
				{
					ln = ln->next;
					return *this;
				}
				self_type operator++(int postfix)
				{
					self_type cpy = *this;
					ln = ln->next;
					return cpy;
				}
				const reference operator * () { return ln->info; }
				const pointer operator -> () { return &(ln->info); }
				bool operator == (const self_type& rhs) const
				{
					if(ln && rhs.ln)
						return ln->info == rhs.ln->info;
					return (!ln && !rhs.ln);
				}
				bool operator != (const self_type& rhs) const { return !(ln->info == rhs.ln->info); }
		};

		SetList( T info = T() ) : head( new ListNode<T>(info, nullptr) ) {}
		SetList( std::initializer_list<T> sl ) : head( sl.head ) { std::uninitialized_copy(sl.begin(), sl.end(), head); }
		int size() { return ListNode<T>::length(head); }
		T& operator [] (int indx) { return ListNode<T>::findByIndex( head, indx ); }
		const T& operator [] (int indx) const { return ListNode<T>::findByIndex( head, indx ); }
		iterator begin() { return iterator( head ); }
		iterator end()
		{
			ListNode<T> * temp = head;
			while( temp->next )
				temp = temp->next;
			return iterator(temp);
		}
		void insert(T info)
		{
			ListNode<T>::insert(head, info);
//			head = new ListNode<T>(info, head);
		}
		iterator find(T info)
		{
			for(ListNode<T> * temp = head; temp; temp = temp->next)
				if ( temp->info == info )
					return iterator(temp);
			return end();
		}
		const_iterator begin() const { return iterator( head ); }
		const_iterator end() const
		{
			ListNode<T> * temp = head;
			while( temp->next )
				temp = temp->next;
			return iterator(temp);
		}
		const_iterator find(T info) const
		{
			for(ListNode<T> * temp = head; temp; temp = temp->next)
				if ( temp->info == info )
					return iterator(temp);
			return end();
		}
		~SetList() { ListNode<T>::deleteList(head); }
};



#endif /* SETLIST_H_ */
