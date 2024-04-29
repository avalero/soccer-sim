#ifndef PARSESEEMESSAGES_H
#define PARSESEEMESSAGES_H

namespace Parser
{
  /**
   * Player the see message from the server
   * @param message see message from the server
   * @return SeeData
   * @example PlayerSeeMessage("(see 0 ((b) 0 0 0 0))") -> SeeData{BallData{0, 0, 0, 0}}
   */
  Player &parseSeeMessage(const std::string &message, Player &player);

  namespace See

  {

    /**
     * Player the ball data from the see message
     * @param message see message from the server
     * @return BallData
     * @example PlayerBallData("((b) 0 0 0 0)" -> BallData{0, 0, 0, 0}
     */
    SeeData &parseBallData(const std::string &message, SeeData &see);

  }
}

#endif // PARSESEEMESSAGES_H