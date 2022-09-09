#include "../flapmap.hh"

void add_sample(uintptr_t start, size_t duration, size_t flapcount) {
    flapmap.insert({start, {start, duration, flapcount}});
}

bool has_sample(uintptr_t t) {
    for (auto it = flapmap.begin(); it != flapmap.end(); ++it) {
        fprintf(stderr, "key %zu, value %s\n", it->first, it->second);
        if (it->first <= t && t < it->first + it->second.duration) {
            return true;
        }
    }
    return false;
}

int main() {

}