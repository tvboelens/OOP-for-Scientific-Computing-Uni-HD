#ifndef MATRIX_HH
#define MATRIX_HH 

#include<vector>

template <typename T>
class Matrix
{
    private:
        int m_numRows{0};
        int m_numCols{0};
        std::vector<std::vector<T>> entries;

    public:
        void resize(int N, int M);
        void resize(int N);
        // access functions
        T& operator()(int i, int j);
        T operator()(int i, int j) const;
        std::vector<T>& operator[](int i);
        std::vector<T> operator[](int i) const;
        // arithmetic functions
        Matrix& operator*=(T x);
        Matrix& operator+=(const Matrix& B);
        // output
        void print() const;
        void print(int i, bool print_row = true) const;
        const int &get_numRows() const { return m_numRows; }
        const int& get_numCols() const { return m_numCols; }
        const std::vector<std::vector<T>>& get_entries() const { return entries; }

        // Constructors
        Matrix(int numRows, int numCols)
            : m_numRows{numRows}, m_numCols{numCols}, entries(numRows)
            {
                for (size_t i = 0; i < entries.size(); ++i)
                {
                    entries[i].resize(numCols);
                }
                    };

        

        Matrix(int N)
                : m_numRows {N}
                , m_numCols {N}
                , entries(N)
                {
                    for (size_t i = 0; i < entries.size(); ++i)
                    {
                        entries[i].resize(N);
                    }
                };
        
        
        Matrix(const Matrix<T>& A)
            : m_numRows{A.get_numRows()}
            , m_numCols{A.get_numCols()}
            , entries{A.get_entries()} 
            {};
};

#endif
