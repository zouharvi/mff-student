class Petr {
	public:
		Petr(int& b): a(b) { } 
	private:
		int& a;
};

int main() {
	Petr p();
	return 0;
}
