for(ll i = n-1; i>=1; i--){
        while(!m1.empty() && a[i] >= (*m1.begin()).ff){
            auto cur = *m1.begin();
            rless[cur.sec] = mp(i,cur.sec);
            m1.erase(m1.begin());
        }
        while(!m2.empty() && a[i] <= (*m2.begin()).ff){
            auto cur = *m2.begin();
            rmore[cur.sec] = mp(i,cur.sec);
            m2.erase(m2.begin());
        }
        m1.insert(mp(a[i],i));
        m2.insert(mp(a[i],i));
    }