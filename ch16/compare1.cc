
template <typename T>
int compare(const T&, const T&);

template <size_t N, size_t M>
int compare(const char (&)[N], const char (&)[M]);



template <>
int compare(const char* const &p1, const char* const &p2)
{
	return strcmp(p1, p2);
}


