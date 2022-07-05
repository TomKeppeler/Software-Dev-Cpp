bool myand(bool a, bool b){
    if (a) {
        if(b){
            return true;
        }else {
            return false;
        }
    } else {
        return false;
    }
}

bool myAndAnd(bool a, bool b){
    if (a) {
        if (b) {
            return true;
        }else {
            return false;
        }
    } else {
        return false;
    }
}

int main()
{
    return 0;
}