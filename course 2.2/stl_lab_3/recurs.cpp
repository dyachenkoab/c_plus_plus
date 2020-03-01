
void list_fill(list<int> &lst) {
    for (int i = 0; i < rand()%15; i++) {
        lst.push_back(rand() % 20);
    }
}

int recurs(list<int>::iterator lst_begin, list<int>::iterator lst_end) {
    if (lst_begin != lst_end) {
        if (distance(lst_begin, lst_end) == 1) {
            cout << *lst_begin;
            return 0;
        }
        --lst_end;
        cout << *lst_begin << " ";
        cout << *lst_end << " ";
        return recurs(++lst_begin, lst_end);
    } else {
        return 0;
    }
}

