#include "Queue.h"

#include <iostream>
#include <set>
#include <tuple>
#include <vector>


using namespace std;

typedef tuple<string, int> rounddata;

//リングバッファ方式のキュー
class QueueData
{
public:
	QueueData(int buffnum = 5) { head = 0; tail = 0; capacity = 0; ring = buffnum; q.resize(buffnum); }

	void Enqueue(rounddata v)
	{
		q[tail] = v;
		tail = (tail + 1) % ring;
		capacity++;
	}
	rounddata Dequque()
	{
		int index = head;
		head = (head + 1) % ring;
		capacity--;
		return q[index];
	}

	bool IsEmpty() { return capacity == 0; }

	//以下はテスト用メソッド
	int GetHead() { return head; }
	int GetTail() { return tail; }

private:
	int head, tail;
	int ring;
	//要素があるか判定するためのもの
	int capacity;
	//配列数は100,000以下までなので固定配列でも良いかも
	vector<rounddata> q;


};


int Queue::Run()
{
	int N, Q;

	//入力例
	cout << "(プロセス数) (クオンタム時間)" << endl;
	cout << "2 100" << endl;
	cout << "name1 250" << endl;
	cout << "name2 80" << endl;
	
	cout << endl;
	
	//プロセス数NとクオンタムQの入力
	cin >> N >> Q;
	QueueData q(N);

	for(int i = 0; i < N; i++)
	{
		string name;
		int time;
		cin >> name >> time;

		q.Enqueue(make_tuple(name, time));
		
	}

	int sumtime = 0;

	cout << "=== output === " << endl;
	while(!q.IsEmpty())
	{
		rounddata r = q.Dequque();
		int t = get<1>(r);
		t -= Q;
		if (t > 0) {
			//残り時間がまだある場合は、再びキューに追加する
			q.Enqueue(make_tuple(get<0>(r), t));
			sumtime += Q;
		}
		else
		{//すべての時間がなくなったら、出力する
			sumtime += get<1>(r);
			cout << get<0>(r) << " " << sumtime << endl;
 		}
	}
	
	
	return 0;
}

void Queue::TestGen()
{
}

