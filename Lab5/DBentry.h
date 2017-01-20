#ifndef _DBENTRY_H
#define _DBENTRY_H

#include <string>
using namespace std;

class DBentry {
private:
	string name;
	unsigned int IPaddress;
        bool active;

public:
	
	DBentry();// the default constructor
        DBentry (string _name, unsigned int _IPaddress, bool _active);
 	~DBentry();// the destructor
	void setName(string _name);// sets the domain name, which we will use as a key.
	void setIPaddress(unsigned int _IPaddress);// sets the IPaddress data.
        void setActive (bool _active);// sets whether or not this entry is active.
	string getName() const;// returns the name.
	unsigned int getIPaddress() const;// returns the IPaddress data.
        bool getActive() const;// returns whether or not this entry is active.

	// prints the entry in the format 
        // name : IPaddress : active  followed by newline
        // active is printed as a string (active or inactive)
        friend ostream& operator<< (ostream& out, const DBentry& rhs);

        
};




#endif 

