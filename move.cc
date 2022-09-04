#include "move.h"

bool moveLegal(CardStorage *from, CardStorage *to) {
    auto card_ref = from->topCard();
    if (card_ref == nullptr)
        return false;

    return to->canAccept(*card_ref);
}

void move(CardStorage *from, CardStorage *to) {
    if (!moveLegal(from, to))
        return;

    to->acceptCard(std::move(from->getCard()));
}
