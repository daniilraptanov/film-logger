import { FC } from "react";

interface TooltipProps {
    message: string;
}

const Tooltip: FC<TooltipProps> = (props) => {
    return (
        <div
            style={{
                position: "fixed",
                bottom: "10%",
                left: "50%",
                transform: "translate(-50%, 0)",
                background: "rgba(0,0,0,0.85)",
                color: "#fff",
                padding: "16px 32px",
                borderRadius: "8px",
                zIndex: 1000,
                boxShadow: "0 2px 12px rgba(0,0,0,0.2)",
                fontSize: "1.1rem",
                pointerEvents: "none",
            }}
        >
            {props.message}
        </div>
    );
};

export default Tooltip;
