/*
 * This file is part of the AzerothCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Log.h"
#include "ScriptMgr.h"
#include "Chat.h"
#include "Player.h"
#include "ScriptedGossip.h"

class TestMail_CS : public CommandScript
{
public:
    TestMail_CS() : CommandScript("TestMail_CS") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> commandTable =
        {
            { "testmailitem", SEC_ADMINISTRATOR, false, &HandleSendItemsCommand, "" }
        };

        return commandTable;
    }

    // Send items by mail
    static bool HandleSendItemsCommand(ChatHandler* handler, char const* args)
    {
        Player* player = handler->GetSession()->GetPlayer();

        if (!player)
            return false;

        player->SendItemRetrievalMail({ { 40265, 15 }, { 40265, 5 }});
        player->SendItemRetrievalMail({ { 49426, 9000 }, { 44615, 50 } });
        
        return true;
    }

};

// Group all custom scripts
void AddSC_TestMail()
{
    new TestMail_CS();
}
