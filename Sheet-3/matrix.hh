#ifndef MATRIX_HH
#define MATRIX_HH 

#include<vector>

class Matrix
{
    private:
        int m_numRows{0};
        int m_numCols{0};
        std::vector<std::vector<double>> entries;

    public:
        void resize(int N, int M);
        void resize(int N);
        void resize(int N, double value);
        void resize(int N, int M, double value);
        // access functions
        double& operator()(int i, int j);
        double operator()(int i, int j) const;
        std::vector<double>& operator[](int i);
        std::vector<double> operator[](int i) const;
        // arithmetic functions
        Matrix& operator*=(double x);
        Matrix& operator+=(const Matrix& B);
        // output
        void print() const;
        void print(int i, bool print_row) const;
        const int &get_numRows() const { return m_numRows; }
        const int& get_numCols() const { return m_numCols; }
        const std::vector<std::vector<double>>& get_entries() const { return entries; }

        // Constructors
        Matrix(int numRows, int numCols)
            : m_numRows{numRows}, m_numCols{numCols}, entries(numRows)
            {
                for (size_t i = 0; i < entries.size(); ++i)
                {
                    entries[i].resize(numCols);
                }
                    };

        Matrix(int numRows, int numCols, double value) 
            {
                resize(numRows, numCols, value);
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
        
        Matrix(int N, double value) 
            {
                resize(N, value);
            };
        
        Matrix(const Matrix &A)
            : m_numRows{A.get_numRows()}
            , m_numCols{A.get_numCols()}
            , entries{A.get_entries()} 
            {};
};

#endif
