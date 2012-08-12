package fr.kissy.hellion.server.handler.message.impl;

import fr.kissy.hellion.proto.DownstreamMessageDto;
import fr.kissy.hellion.proto.UpstreamMessageDto;
import fr.kissy.hellion.server.handler.message.MessageHandler;
import org.apache.shiro.SecurityUtils;
import org.apache.shiro.authc.AuthenticationException;
import org.apache.shiro.authc.UsernamePasswordToken;
import org.apache.shiro.subject.Subject;

import java.util.logging.Logger;

/**
 * @author Guillaume Le Biller <lebiller@ekino.com>
 * @version $Id$
 */
public class AuthenticateMessageHandler implements MessageHandler {

    private static final Logger LOGGER = Logger.getLogger(AuthenticateMessageHandler.class.getName());

    /**
     * @inheritDoc
     */
    @Override
    public UpstreamMessageDto.UpstreamMessageProto.Builder process(DownstreamMessageDto.DownstreamMessageProto message) {
        if (message.getType() != DownstreamMessageDto.DownstreamMessageProto.Type.AUTHENTICATE) {
            return null;
        }

        Subject user = SecurityUtils.getSubject();
        if (user.isAuthenticated()) {
            return null;
        }

        String username = new String(message.getData().toByteArray());
        UsernamePasswordToken usernamePasswordToken = new UsernamePasswordToken(username, "test");
        LOGGER.fine("Authentication attempt for user " + usernamePasswordToken.toString());
        try {
            user.login(usernamePasswordToken);
        } catch (AuthenticationException ignored) {
            LOGGER.warning("Authentication failed for user " + usernamePasswordToken.toString());
            UpstreamMessageDto.UpstreamMessageProto.Builder builder = UpstreamMessageDto.UpstreamMessageProto.newBuilder();
            builder.setType(UpstreamMessageDto.UpstreamMessageProto.Type.UNAUTHORIZED);
            return builder;
        }

        UpstreamMessageDto.UpstreamMessageProto.Builder builder = UpstreamMessageDto.UpstreamMessageProto.newBuilder();
        builder.setType(UpstreamMessageDto.UpstreamMessageProto.Type.AUTHENTICATED);
        return builder;
    }
}