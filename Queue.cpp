#include <iostream>
#include <set>
#include <tuple>
#include <vector>


using namespace std;

typedef tuple<string, int> rounddata;

//�����O�o�b�t�@�����̃L���[
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

	//�ȉ��̓e�X�g�p���\�b�h
	int GetHead() { return head; }
	int GetTail() { return tail; }

private:
	int head, tail;
	int ring;
	//�v�f�����邩���肷�邽�߂̂���
	int capacity;
	//�z�񐔂�100,000�ȉ��܂łȂ̂ŌŒ�z��ł��ǂ�����
	vector<rounddata> q;


};

void Queue()
{
	int N, Q;

	//���͗�
	cout << "(�v���Z�X��) (�N�I���^������)" << endl;
	cout << "2 100" << endl;
	cout << "name1 250" << endl;
	cout << "name2 80" << endl;
	
	cout << endl;
	
	//�v���Z�X��N�ƃN�I���^��Q�̓���
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
			//�c�莞�Ԃ��܂�����ꍇ�́A�ĂуL���[�ɒǉ�����
			q.Enqueue(make_tuple(get<0>(r), t));
			sumtime += Q;
		}
		else
		{//���ׂĂ̎��Ԃ��Ȃ��Ȃ�����A�o�͂���
			sumtime += get<1>(r);
			cout << get<0>(r) << " " << sumtime << endl;
 		}
	}
	
	
	
}

