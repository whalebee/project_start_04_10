int main()
{
	// 1��
	char season[10] = { '��', '����', '����', '�ܿ�' };

	// end ������ ��
	while (1)
	{
		printf("-------- 4���� �� �� ���� ���� (����� end) : ");
		scanf("%s", season);

		if (strcmp(season, "��") == 0)
		{
			printf("������ ���� \n");
		}
		else if (strcmp(season, "����") == 0)
		{
			printf("�������� ��� \n");
		}
		else if (strcmp(season, "����") == 0)
		{
			printf("�������� �ڽ��� \n");
		}
		else if (strcmp(season, "�ܿ�") == 0)
		{
			printf("�ܿ￡�� ��ȭ \n");
		}
		else if (strcmp(season, "end") == 0)
		{
			printf("end�Է����� �շ� \n");
			break;
		}
		else
		{
			printf("??? �ٽ� �Է� \n");
		}
	}



	return 0;
}