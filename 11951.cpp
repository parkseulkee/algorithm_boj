// JOI국의 산책 : DP?

// 좌표는 오름차순으로 입력됨

// 가장 가까운 점 두개가 반대쪽으로 이동하면 만남
// 그러면 멈춤, 멈추는 좌표 : 두 개 좌표의 합 / 2

// T > 현재 내 좌표 - 멈춰있는 좌표 이면
// 나는 움직이다가 멈춰있는 애들 만나면 멈춤 : 내 좌표 <= 멈춰있는 좌표


#include <cstdio>
#include <algorithm>
using namespace std;

struct AA {
	long long int x;
	int dir;
};

struct STOP {
	int idx;
	long long int x;
};

AA A[100001];
STOP S[100001];
long long int R[100001];	// result value


int main()
{
	int n, q, stopCnt = 1;
	long long int t;
	scanf("%d %lld %d", &n, &t, &q);

	for (int i = 1;i <= n;++i) {
		scanf("%lld %d", &A[i].x, &A[i].dir);
		if (A[i - 1].dir == 1 && A[i].dir == 2) {
			S[stopCnt].idx = i - 1;
			S[stopCnt++].x = (A[i - 1].x + A[i].x) / 2;
		}
	}
	S[stopCnt++].idx = n+1;
	for (int i = 1, j = 1;i <= n;++i) {
		if (i > S[j].idx) j++;
		if (A[i].dir == 1) {
			R[i] = A[i].x + (j < stopCnt-1 ? min(S[j].x - A[i].x, t) : t);
		}
		else {
			R[i] = A[i].x - (j > 1 ? min(A[i].x - S[j - 1].x, t) : t);
		}
	}

	int idx;
	for (int i = 0;i < q;++i) {
		scanf("%d", &idx);
		printf("%lld\n", R[idx]);
	}
	return 0;
}