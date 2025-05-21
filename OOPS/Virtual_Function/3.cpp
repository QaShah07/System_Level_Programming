// Interface class
class Database {
public:
	// this will read rows from database.
	virtual void Read() = 0;
	// thiw will write rows in database
	virtual void write() = 0;
	// Execute SQL query on database.
	virtual void Query() = 0;
};


class MySQL : public Database 
{
public:
	// ....
};


class DynamoDB: public Database
{
	//
};

class SpannerDB: public Database
{
	//
};