#include <map>
#include <string>
#include <memory>
#include <sstream>

namespace grs
{

/*
	������ ������, ��� ��������� ���� ��� �������� ��������
 */

template <class Base>
class AbstractCreator
{
public:
	AbstractCreator()
	{
	}

	virtual ~AbstractCreator()
	{
	}

	virtual Base* create() const = 0;

private:
	AbstractCreator(const AbstractCreator&);
	AbstractCreator& operator = (const AbstractCreator&);
};


template <class C, class Base>
class Creator : public AbstractCreator<Base>
{
public:
	Creator()
	{
	}

	virtual ~Creator()		
	{
	}

	Base * create() const
	{
		return new C();
	}
};

/*
	�������� ��� �������
 */

class ObjectFactoryException : public std::exception
{
	std::string	_msg;
public:
	ObjectFactoryException(const std::string & msg) throw() : _msg(msg) {}
	virtual ~ObjectFactoryException() throw() {}
	
	virtual const char * what() const throw()
	{
		return _msg.c_str();
	}
};

template <class Base, class Type>
class ObjectFactoryIgnoreErrorPolicy
{
public:
	Base * onCreateFailed(const Type & type) const
	{
		return 0;
	}
	void onRemoveFailed(const Type & type)
	{
	}
	void onDuplicateRegistered(const Type & type)
	{
	}
};

template <class Base, class Type>
class ObjectFactoryThrowExceptionErrorPolicy
{
public:
	std::string generateMessage(const char * msg, const Type & type) const
	{
		std::stringstream strm;
		strm << msg << ", requested type id : " << type;
		return strm.str();
	}

	Base * onCreateFailed(const Type & type) const
	{
		throw ObjectFactoryException(generateMessage("ObjectFactory - can't create object (not registered)", type));
	}

	void onRemoveFailed(const Type & type)
	{
		throw ObjectFactoryException(generateMessage("ObjectFactory - can't remove class (not registered)", type));
	}
	
	void onDuplicateRegistered(const Type & type)
	{
		throw ObjectFactoryException(generateMessage("ObjectFactory - class already registered", type));
	}
};

/*
	�������
 */

template <class Base, class IdType = std::string, template <class, class> class ObjectFactoryErrorPolicy = ObjectFactoryIgnoreErrorPolicy >
class ObjectFactory : public ObjectFactoryErrorPolicy<Base, IdType>
{
protected:
	typedef AbstractCreator<Base> AbstractFactory;
	typedef std::map<IdType, AbstractFactory*> FactoryMap;

public:
	ObjectFactory()
	{
	}

	virtual ~ObjectFactory()
	{
		for (typename FactoryMap::iterator it = _map.begin(), endIt = _map.end(); it != endIt; ++it)	
			delete it->second;
	}

	Base * create(const IdType & id) const
	{
		typename FactoryMap::const_iterator it = _map.find(id);
		if (it != _map.end())
			return it->second->create();
		return nullptr;
	}

	template <class C>
	bool add(const IdType & id)
	{
		return registerClass(id, new Creator<C, Base>);
	}

	void remove(const IdType & id)
	{
		typename FactoryMap::iterator it = _map.find(id);
		if (it != _map.end())
		{
			delete it->second;
			_map.erase(it);
		}
		else
			onRemoveFailed(id);
	}

	bool isRegistered(const IdType & id) const
	{
		return _map.find(id) != _map.end();
	}

	size_t size() const
	{
		return _map.size();
	}

  IdType GetId(const int & pos)
  {
    if (pos < 0 || pos >= _map.size())
      return "";
    typename FactoryMap::iterator it = _map.begin();
    for (int i=1; i<=pos; i++)
      it++;
    return it->first;
  }
	
	
protected:
	bool registerClass(const IdType & id, AbstractFactory * pAbstractFactory)
	{
		std::auto_ptr<AbstractFactory> ptr(pAbstractFactory);
		typename FactoryMap::iterator it = _map.find(id);
		if (it == _map.end())
    {
      _map[id] = ptr.release();
      return true;
    }
		return false;
	}

private:
	ObjectFactory(const ObjectFactory&);
	ObjectFactory& operator = (const ObjectFactory&);	

	FactoryMap _map;
};

}	// end of grs namespace