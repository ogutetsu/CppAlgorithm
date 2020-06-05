#include <iostream>
#include <tuple>
#include <vector>


using namespace std;

typedef tuple<string, int> rounddata;

class QueueData
{
public:
	QueueData(int buffnum = 5) { head = 0; tail = 0; ring = buffnum; q.resize(buffnum); }

	void Enqueue(rounddata v) { q[tail++] = v; OverflowTail(); }
	rounddata Dequque() { return q[head++]; OverflowHead(); }

	bool IsEmpty() { return head == tail; }
	
private:
	int head, tail;
	int ring;
	//配列数は100,000以下までなので固定配列でも良いかも
	vector<rounddata> q;

	void OverflowTail() { if(tail > ring) tail = 0; }
	void OverflowHead() { if (head > ring) head = 0; }
	
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

	
	
	
	
}

