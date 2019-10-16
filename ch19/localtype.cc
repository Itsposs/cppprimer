


int a, val;
void foo(int val) {
	static int si;
	enum Loc { a = 1024, b };

	// Bar是foo的局部类
	struct Bar {
		Loc locVal;
		int barVal;

		void fooBar(Loc l = a) {
			barVal = val;  // error
			barVal = ::val;
			barVal = si;
			locVal = b;
		}
	};
}
