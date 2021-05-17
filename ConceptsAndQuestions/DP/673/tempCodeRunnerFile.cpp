 for(ll i = 0; i<f.size(); i++){
        ll q = cur/f[i];
        if(q){
            num.pb(q);
            den.pb(n/f[i]);
        }
        cur -= q*f[i];
    }