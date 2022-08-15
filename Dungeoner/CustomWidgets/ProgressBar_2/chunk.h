#ifndef CHUNK_H
#define CHUNK_H


class Chunk
{
public:
    Chunk();
    Chunk(int maxValue, int value);

    int getMaxValue() const;
    void setMaxValue(int newMaxValue);

    int getValue() const;
    void setValue(int newValue);

private:
    int maxValue = 0;
    int value = 0;
};

#endif // CHUNK_H
