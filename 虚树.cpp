int cnt = 1, top = 1;
for (int i = 2; i <= k; i++)
	if (getlca(arr[i], arr[cnt]) != arr[cnt]) arr[++cnt] = arr[i];
stk[1] = 1;
for (int i = 1; i <= cnt; i++){
	int tmp = getlca(arr[i], stk[top]);
	while (1) {
		if (deep[stk[top - 1]] <= deep[tmp]){
			if (top > 1) {
				vedges[tmp].push_back(stk[top]);
			}
			top--;
			if (stk[top] != tmp) stk[++top] = tmp;
			break;
		}
		vedges[stk[top - 1]].push_back(stk[top]);
		top--;
	}
	if (stk[top] != arr[i]) stk[++top] = arr[i];
}
while (top > 1){
	vedges[stk[top - 1]].push_back(stk[top]);
	top--;
}