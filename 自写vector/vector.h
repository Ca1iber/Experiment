#pragma once


template<typename T>
class Vector
{
public:
	Vector()
	{
		ReAlloc(2);
	}

	~vector()
	{
		delete[] m_Data;
	}
	void PushBack(const T& value)
	{
		if (m_Size >= m_Capacity)//Խ���飬��ʱ����
		{
			ReAlloc(m_Capacity + m_Capacity / 2);
		}
		m_Data[m_Size] = value;
		m_Size++;
	}

	void PushBack(T&& value)
	{
		if (m_Size >= m_Capacity)//Խ���飬��ʱ����
		{
			ReAlloc(m_Capacity + m_Capacity / 2);
		}
		m_Data[m_Size] = std::move(value);//�������ƶ������⸴��
		m_Size++;
	}

	template<typename... Args>
	T& EmplaceBack(Args&&... ags)
	{
		if (m_Size >= m_Capacity)//Խ���飬��ʱ����
		{
			ReAlloc(m_Capacity + m_Capacity / 2);
		}
		m_Data[m_Size] = T(std::forward<Args>(ags)...);
		return m_Data[m_Size++];
	}

	void PopBack()
	{
		if (m_Size > 0)
		{
			m_Size--;
			m_Data[m_Size].~T();
		}
	}

	void Clear()
	{
		for (size_t i = 0; i < m_Size; i++)
		{
			m_Data[i].~T();
		}
		m_Size = 0;
	}

	T& operator[] (size_t index) const//��ѯvector��С
	{
		return m_Data[index];
	}

	const T& operator[] (size_t index)
	{
		return m_Data[index];
	}

	size_t Size()const { return m_Size; }
private:
	void ReAlloc(size_t newCapacity)
	{
		//1.�����µ��ڴ�ռ�
		//2.��������֮ǰ������Ϣ���µ��ڴ�ռ���->���������Ż�Ϊ�ƶ�
		//3.ɾ���ɵ��ڴ�ռ�
		T* newBlock = new T[newCapacity];
		//�ж��費��Ҫ����
		size_t size = m_Size;
		if (newCapacity < size)
			size = newCapacity;

		for (int i = 0; i < m_Size; i++)
		{
			newBlock[i] = std::move(m_Data[i]);//�Ż�Ϊ�ƶ����⸴���˷���Դ
		}
		delete[] m_Data;
		m_Data = newBlock;
		m_Capacity = newCapacity;
	}
private:
	T* m_Data = nullptr;
	size_t m_Size = 0;
	size_t m_Capacity = 0;
};
