#ifndef IntCell_H
#define IntCell_H

class IntCell {
    public:
        explicit IntCell(int value = 1);
        int read() const;
        void write(int value);
    private:
        int m_storedValue;
};

#endif
