ListNode* swapPairs(ListNode* head) 
{
	ListNode* tail = NULL;
	ListNode* newHead = NULL;
	ListNode* p1 = head;
	ListNode* p2;

	while (p1 && p1->next)
	{
		p2 = p1->next;

		if (newHead == NULL)
		{
			newHead = p2;
		}
		else
		{
			tail->next = p2;
		}

		tail = p1;
		p1->next = p2->next;
		p2->next = p1;
		p1 = p1->next;
	}

	if (!newHead)
	{
		return head;
	}

	return newHead;
}