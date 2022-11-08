#include <stdio.h>
#include <inttypes.h>

int64_t invmod(int64_t a, int64_t m)
{
	int64_t m0 = m, y = 0, x = 1, q, t;

	if (m == 1)
		return 0;

	while (a > 1)
	{
		q = a / m;
		t = m;

		m = a % m, a = t;
		t = y;

		y = x - q * y;
		x = t;
	}

	return (x < 0? x + m0: x);
}

void solve(int64_t h, int64_t k, int64_t N) {
	int64_t y0 = invmod(h, k);
	int64_t x0 = (h*y0 - 1) / k;
	int64_t ts = (N - y0) / k;

	int64_t as = x0 + h*ts;
	int64_t bs = y0 + k*ts;

	printf("%" PRId64 " %" PRId64 "\n", as, bs);
}

int main()
{
	int t;


	int a=3, b = 7;
	int64_t N = 1000000;
	solve(a, b, N);

    return 0;
}
