#include <vector>

class Buffer
{
public:
    Buffer(const std::string& buff)
    :   pBuff(nullptr)
    ,   buffSize(buff.length())
    {
        pBuff = new char[buffSize];
        memcpy(pBuff, buff.c_str(), buffSize);
    }

    ~Buffer(){ destroy(); }

    Buffer(const Buffer& other)
    :   pBuff(nullptr)
    ,   buffSize(other.buffSize)
    {
        pBuff = new char[buffSize];
        memcpy(pBuff, other.pBuff, buffSize);
    }

    Buffer& operator=(const Buffer& other)
    {
        destroy();
        buffSize = other.buffSize;
        pBuff = new char[buffSize];
        memcpy(pBuff, other.pBuff, buffSize);
        return *this;
    }

    Buffer(Buffer&& tmp)
    :   pBuff(tmp.pBuff)
    ,   buffSize(tmp.buffSize)
    {
        tmp.pBuff = nullptr;
    }

    Buffer& operator=(Buffer&& tmp)
    {
        destroy();
        buffSize = tmp.buffSize;
        pBuff = tmp.pBuff;
        tmp.pBuff = nullptr;
        return *this;
    }

private:
    void destroy()
    {
        if (pBuff)
            delete[] pBuff;
    }

    char* pBuff;
    size_t buffSize;
};

Buffer CreateBuffer(const std::string& buff)
{
    Buffer retBuff(buff);
    return retBuff;
}

int main()
{
    Buffer buffer1 = CreateBuffer("123"); // срабатывает конструктор перемещения
    Buffer buffer2 = buffer1;             // срабатывает конструктор копирования
    buffer2 = CreateBuffer("123");        // срабатывает конструктор перемещения, затем оператор перемещения
    buffer2 = buffer1;                    // срабатывает оператор присваивания
}
