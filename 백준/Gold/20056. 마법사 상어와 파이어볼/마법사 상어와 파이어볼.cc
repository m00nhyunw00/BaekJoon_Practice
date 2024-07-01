#include <iostream>
#include <vector>
#define MAX 51

using namespace std;

// 파이어볼 정보 클래스
class fireball{
public:
    int x;
    int y;
    int massive;
    int speed;
    int direction;

    fireball(int r, int c, int m, int s, int d){
        x = r;
        y = c;
        massive = m;
        speed = s;
        direction = d;
    }
};

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int N, M ,K;                        // 격자 길이 | 파이어볼 갯수 | 명령 횟수
int result = 0;                      // 파이어볼 총 질량
vector<fireball> MAP[MAX][MAX];     // 격자 맵
vector<fireball> FireBalls;         // 파이어볼 정보 스택

void simulation();                  // 파이어볼 시뮬레이션 실행 함수

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    int r, c, m, s ,d;

    for (int i=0; i<M; i++){
        cin >> r >> c >> m >> s >> d;
        fireball fb(r, c, m, s, d);
        MAP[r][c].push_back(fb);
        FireBalls.push_back(fb);
    }

    simulation();

    cout << result;

    return 0;
}

void simulation(){
    for (int n=0; n<K; n++){

        // 이동 후의 맵을 저장할 임시 배열
        vector<fireball> Temp[MAX][MAX];

        // 파이어볼 이동 파트
        for (fireball& fb : FireBalls){
            int x = fb.x;
            int y = fb.y;
            int speed = fb.speed;
            int mass = fb.massive;
            int dir = fb.direction;

            // 이동 거리 계산
            int move_dist = speed % N;

            // 새로운 위치 계산
            int nx = x + move_dist * dx[dir];
            int ny = y + move_dist * dy[dir];

            // 맵 경계를 벗어나면 반대편으로 이동
            if (nx < 1) nx += N;
            if (ny < 1) ny += N;
            if (nx > N) nx -= N;
            if (ny > N) ny -= N;

            // 이동한 파이어볼 정보를 임시 배열에 저장
            Temp[nx][ny].push_back(fireball(nx, ny, mass, speed, dir));
        }

        // 임시 배열을 기존 맵에 복사
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                MAP[i][j] = Temp[i][j];
            }
        }

        // 파이어볼 합체 파트
        FireBalls.clear();

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (MAP[i][j].size() <= 1) {
                    if (!MAP[i][j].empty()) {
                        FireBalls.push_back(MAP[i][j][0]);
                    }
                    continue;
                }

                int total_mass = 0;
                int total_speed = 0;
                bool all_even = true;
                bool all_odd = true;

                for (const auto& fb : MAP[i][j]) {
                    total_mass += fb.massive;
                    total_speed += fb.speed;
                    if (fb.direction % 2 == 0) {
                        all_odd = false;
                    } else {
                        all_even = false;
                    }
                }

                int new_mass = total_mass / 5;
                int new_speed = total_speed / MAP[i][j].size();

                if (new_mass == 0) continue;

                if (all_even || all_odd) {
                    for (int dir = 0; dir < 8; dir += 2) {
                        FireBalls.push_back(fireball(i, j, new_mass, new_speed, dir));
                    }
                } else {
                    for (int dir = 1; dir < 8; dir += 2) {
                        FireBalls.push_back(fireball(i, j, new_mass, new_speed, dir));
                    }
                }
            }
        }
    }

    // 남아있는 파이어볼 질량의 합 계산
    for (const auto& fb : FireBalls) {
        result += fb.massive;
    }
}