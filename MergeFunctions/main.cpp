#include <iostream>
#include <list>
#include <set>
#include <string_view>
#include <vector>

using namespace std;

// �������� ��������� ���� �������, ����� ��� �����
// ������� �� ������ �������, �� � ����� ������ ����������
template <typename InputIt1, typename InputIt2>
void Merge(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, ostream& out) {
    InputIt1 src1 = first1;
    InputIt2 src2 = first2;
    while (src1 != last1 && src2 != last2) {
        if (less<>()(*src1, *src2)) {
            out << *src1 << endl;
            ++src1;
        }
        else {
            out << *src2 << endl;
            ++src2;
        }
    }
    while (src1 != last1) {
        out << *src1 << endl;
        ++src1;
    }
    while (src2 != last2) {
        out << *src2 << endl;
        ++src2;
    }
}

/*template <typename T>
void Merge(const vector<T>& src1, const vector<T>& src2, ostream& out) {
    size_t i1 = 0, i2 = 0;
    while (i1 < src1.size() && i2 < src2.size()) {
        if (src1[i1] < src2[i2]) {
            out << src1[i1++] << endl;
        }
        else {
            out << src2[i2++] << endl;
        }
    }
    while (i1 < src1.size()) {
        out << src1[i1++] << endl;
    }
    while (i2 < src2.size()) {
        out << src2[i2++] << endl;
    }
}*/

template <typename T>
void MergeSomething(const vector<T>& src1, const vector<T>& src2, ostream& out) {
    Merge(src1.begin(), src1.end(), src2.begin(), src2.end(), out);
}

// ���������� ��� �������. ��� ������ �������� ��� ������� ������� Merge.
// ����� ��������� ��������� ������, ������ ����������� ������ ��� ���� ���������.
template <typename T, typename S>
void MergeSomething(const list<T>& src1, const vector<S>& src2, ostream& out) {
    Merge(src1.begin(), src1.end(), src2.begin(), src2.end(), out);
}

template <typename T, typename S>
void MergeSomething(const vector<T>& src1, const list<S>& src2, ostream& out) {
    Merge(src1.begin(), src1.end(), src2.begin(), src2.end(), out);
}

template <typename S>
void MergeSomething(const string_view& src1, const list<S>& src2, ostream& out) {
    Merge(src1.begin(), src1.end(), src2.begin(), src2.end(), out);
}

template <typename T, typename S>
void MergeSomething(const set<T>& src1, const vector<S>& src2, ostream& out) {
    Merge(src1.begin(), src1.end(), src2.begin(), src2.end(), out);
}

// ���������� ��� �������:
template <typename T>
void MergeHalves(const vector<T>& src, ostream& out) {
    size_t mid = (src.size() + 1) / 2;
    auto mid_it = src.begin();
    std::advance(mid_it, mid);
    // ������� Merge ������� ������� �� 0 �� mid � �� mid �� �����.
    // ������� � �������� mid ���������� �� ������ ��������.
    Merge(src.begin(), mid_it, mid_it, src.end(), out);
}

int main() {
    vector<int> v1{ 60, 70, 80, 90 };
    vector<int> v2{ 65, 75, 85, 95 };
    vector<int> combined{ 60, 70, 80, 90, 65, 75, 85, 95 };
    list<double> my_list{ 0.1, 72.5, 82.11, 1e+30 };
    string_view my_string = "ACNZ"sv;
    set<unsigned> my_set{ 20u, 77u, 81u };

    // ���� ������� MergeSomething ����������� ���� ������ ��� ��������
    cout << "Merging vectors:"sv << endl;
    MergeSomething(v1, v2, cout);

    cout << "Merging vector and list:"sv << endl;
    MergeSomething(v1, my_list, cout);

    cout << "Merging string and list:"sv << endl;
    MergeSomething(my_string, my_list, cout);

    cout << "Merging set and vector:"sv << endl;
    MergeSomething(my_set, v2, cout);

    cout << "Merging vector halves:"sv << endl;
    MergeHalves(combined, cout);
}