#ifndef CLIQUE_HASH
#define CLIQUE_HASH

#include "constants.h"

//hash(C)= (\sum_{v_i \in C}2^i) mod p, where p = PRIME_NUM

class CliqueHash{
private:
	int* two_power_mod_p;
	char* hash_entries;
	int curr_hash_entry;
	int hash_bound;
public:
	CliqueHash(int v_num)
	{
        cout << NEW_PRIME << "\n";
		two_power_mod_p = new int[v_num + 2];
		two_power_mod_p[0] = 1;
		for(int v = 1; v <= v_num; v++)
		{
			two_power_mod_p[v] = (two_power_mod_p[v-1] * 2) % NEW_PRIME;
			//cout << two_power_mod_p[v] << "\n";

		}

///////////////////////////////////////////////
		hash_entries = new char[PRIME_NUM];
		memset(hash_entries, 0, sizeof(char) * NEW_PRIME);
///////////////////////////////////////////////
		curr_hash_entry = 0;
		hash_bound = 1;
	}
	~CliqueHash()
	{
		delete[] two_power_mod_p;
		delete[] hash_entries;
	}
	void reset_hash_entry()
	{
		curr_hash_entry = 0;
	}
	void update_hash_wrt_add(int v)
	{
		curr_hash_entry = (curr_hash_entry + two_power_mod_p[v]) % NEW_PRIME;
		cout << v << " add: " << curr_hash_entry << "\n";
	}
	void update_hash_wrt_drop(int v)
	{
		curr_hash_entry = (curr_hash_entry + NEW_PRIME - two_power_mod_p[v]) % NEW_PRIME;
		cout << v << " update: " << curr_hash_entry << "\n";
	}
	void mark_hash_entry()
	{
		hash_entries[curr_hash_entry]++;
	}
	int curr_hash_entry_marked_too_frequently()
	{

		if(hash_entries[curr_hash_entry] > hash_bound) { cout << "TOO FREQUENT \n"; return 1;}
		cout << "NOT TOO FREQUENT \n";
			return 0;
	}

};

#endif
