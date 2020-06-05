#include <iostream>
#include <set>
#include <tuple>
#include <vector>


using namespace std;

typedef tuple<string, int> rounddata;

class QueueData
{
public:
	QueueData(int buffnum = 5) { head = 0; tail = 0; ring = buffnum; q.resize(buffnum); }

	void Enqueue(rounddata v) { q[tail++] = v; OverflowTail(); }
	rounddata Dequque() { OverflowHead(); return q[head++];  }

	bool IsEmpty() { return head == tail; }
	
private:
	int head, tail;
	int ring;
	//配列数は100,000以下までなので固定配列でも良いかも
	vector<rounddata> q;

	void OverflowTail() { if(tail >= ring) tail = 0; }
	void OverflowHead() { if (head >= ring) head = 0; }
	
};

void Queue()
{
	int N, Q;

	QueueData q;

	//プロセス数NとクオンタムQの入力
	cin >> N >> Q;
	for(int i = 0; i < N; i++)
	{
		string name;
		int time;
		cin >> name >> time;

		q.Enqueue(make_tuple(name, time));
		
	}

	int ptime = 0;
	
	while(!q.IsEmpty())
	{
		rounddata r = q.Dequque();
		int t = get<1>(r);
		t -= Q;
		if (t > 0) {
			q.Enqueue(make_tuple(get<0>(r), t));
			ptime += Q;
		}
		else
		{
			ptime += t;
			cout << get<0>(r) << " " << ptime << endl;
 		}
	}
	
	
	
}

