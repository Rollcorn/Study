#include "dictionary.hpp"

template<class TKey>
class MyNotFoundException : public NotFoundException<TKey> {
public:
    const TKey& GetKey() const noexcept override
    {
        return m_key;
    }

    explicit MyNotFoundException(const TKey& key) : m_key(key){
    }

private:
    TKey m_key;
};

template<class TKey, class TValue>
class MyDictionary : public std::map<TKey, TValue>, public Dictionary<TKey, TValue>{
    public:
        MyDictionary<TKey, TValue>() : m_container(new std::map<TKey, TValue>)
        {}

        ~MyDictionary() override{
            delete m_container;
        };

        bool IsSet(const TKey& key) const override{
            return m_container->find(key) != m_container->end();
        }
//Доступ к значению эле
        const TValue& Get(const TKey& key) const override{
        try {
            if (!IsSet(key))
                throw MyNotFoundException<TKey>(key);
        }catch (MyNotFoundException<TKey> &ex){
            std::cerr << ex.GetKey() << " Not found" <<std::endl;
        }
        return (*m_container)[key];
        }

        void Set(const TKey& key, const TValue& value) override{
            //container->at(key) = value;
            (*m_container)[key] = value;
        }

    auto operator[](const TKey& key){
        try {
            if (!IsSet(key))
                throw MyNotFoundException<TKey>(key);
        }catch (MyNotFoundException<TKey> &ex){
            std::cerr << ex.GetKey() << " Not found" <<std::endl;
        }
        return (*m_container)[key];
    }

    private:
        std::map<TKey, TValue> *m_container;
    };


int main(){
        //
        MyDictionary<int, std::string> m;
        m.Set(1, "One");
        m.Set(2, "Two");
        m.Set(3, "Three");
        m.Set(4, "Four");

        std::cout << m.Get(1) << std::endl;
        std::cout << m.Get(2) << std::endl;
        std::cout << m.Get(3) << std::endl;
        std::cout << m.Get(4) << std::endl;
        std::cout << m.Get(5) << std::endl;

        std::cout << m[1] << std::endl;
        std::cout << m[2] << std::endl;
        std::cout << m[3] << std::endl;
        std::cout << m[4] << std::endl;
        std::cout << m[5] << std::endl;
        std::cout << m[6] << std::endl;


    return 0;
    }
