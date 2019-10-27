class User 
{
    public:
        User( const char * name, int id, int ssn): _id(id), _ssn(ssn)
        {
            int len = strlen(name);
            _name = new char[len +1];
            memcpy(_name, name, len + 1);
        }

        User & operator = (const User & user)
        {
            if (this != &user)
            {
                auto tmp = _name;
                int len = strlen(user._name);
                _name = new char[len +1];
                memcpy(_name, user._name, len+1);
                _id = user._id;
                const_cast<int&>(_ssn) = user._ssn;
                delete tmp;
            }
            return *this;
        }

        ~User() 
        {
            delete _name; 
        }
    char *  _name = nullptr;
    int     _id;
    const int _ssn;
};